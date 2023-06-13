#include "DDM_khepera_loop_function.h"
#include <sstream>
#include <list>
#include <stdlib.h>
#include <math.h>
#include <cmath>

using namespace argos;

static std::string POSTITIONFILE_PREFIX = "pos_";
static std::string PERF_PREFIX = "perf_";

static const Real KH_RADIUS = 0.0704f;
static const Real KH_AREA = ARGOS_PI * Square(0.0704f);
static const std::string KH_CONTROLLER = "khivbz";
static const UInt32 MAX_PLACE_TRIALS = 4000;

void DDMKheperaLoopFunction::Init(TConfigurationNode &t_tree)
{

    try
    {

        GetNodeAttribute(t_tree, "robots", unRobots);
        GetNodeAttribute(t_tree, "rab_range", rab_range);
        GetNodeAttribute(t_tree, "rab_range_beacon", rab_range_beacon);
        GetNodeAttribute(t_tree, "rab_data_size", unDataSize);
        GetNodeAttribute(t_tree, "seed", seed);
        GetNodeAttribute(t_tree, "dir", dir);
        GetNodeAttribute(t_tree, "out_file", out_file);
        GetNodeAttribute(t_tree, "fill_ratio_white", fill_ratio_white);
        GetNodeAttribute(t_tree, "fill_ratio_black", fill_ratio_black);

        m_pcFloor = &GetSpace().GetFloorEntity();
        m_pcRNG = CRandom::CreateRNG("argos");

        m_strOutFile = ".txt";
        POSTITIONFILE_PREFIX += out_file + "_" + std::to_string(unRobots) + "_"+std::to_string(int(rab_range*10)) + "_" + std::to_string(seed);
        PERF_PREFIX += out_file + "_" + std::to_string(unRobots) + "_"+std::to_string(int(rab_range*10)) + "_" + std::to_string(seed);


        PlaceUniformly(unRobots, unDataSize, rab_range, rab_range_beacon);
        

        Reset();
    }
    catch (CARGoSException &ex)
    {
        THROW_ARGOSEXCEPTION_NESTED("Error initializing the loop functions", ex)
    }
}

void DDMKheperaLoopFunction::PostStep()
{

    if (out_file == "movement_congestion"){
        UInt32 collisions = 0;
        std::string state;
        Real estimate = 0.0f;
        UInt32 convergence_white = 0;
        UInt32 convergence_black = 0;
        UInt32 unassigned = 0;
        UInt32 white_neighbors = 0;
        UInt32 black_neighbors = 0;
        float white_neighbors_ratio = 0.0f;
        float black_neighbors_ratio = 0.0f;
        float white_neighbors_aggregate = 0.0f;
        float black_neighbors_aggregate = 0.0f;
        bool decision_flag = false;

        int zone_collected = 0;

        m_perfFile << GetSpace().GetSimulationClock() << "," << seed << "," << unRobots;
        m_posFile << GetSpace().GetSimulationClock() << "," << seed << "," << unRobots;
        for (int i = 0; i < unRobots; i++)
        {

            buzzvm_t vm = m_buzz_ctrl[i];
            collisions = buzzobj_getint(BuzzGet(vm, "collisions"));
            zone_collected = buzzobj_getint(BuzzGet(vm, "zone_collected"));
            state = buzzobj_getstring(BuzzGet(vm, "BVMSTATE"));
            estimate = buzzobj_getfloat(BuzzGet(vm, "new_belief"));
            white_neighbors = buzzobj_getint(BuzzGet(vm, "white_neighbors"));
            black_neighbors = buzzobj_getint(BuzzGet(vm, "black_neighbors"));
            white_neighbors_ratio = buzzobj_getfloat(BuzzGet(vm, "white_aggregate"));
            black_neighbors_ratio = buzzobj_getfloat(BuzzGet(vm, "black_aggregate"));
            white_neighbors_aggregate = buzzobj_getfloat(BuzzGet(vm, "white_ratio"));
            black_neighbors_aggregate = buzzobj_getfloat(BuzzGet(vm, "black_ratio"));
            decision_flag = buzzobj_getint(BuzzGet(vm, "decision_flag"));

        // std::cout<<i<<","<<estimate<<","<<white_neighbors<<","<<black_neighbors<<","<<white_neighbors_aggregate<<","<<black_neighbors_aggregate<<","<<decision_flag<<std::endl;

        m_perfFile << "," << i << "," << collisions << "," << state << "," << estimate << "," << white_neighbors << "," << black_neighbors << "," << white_neighbors_aggregate << "," << black_neighbors_aggregate << "," << decision_flag;
        if (state == "white_exploration" || state == "white_followers" || (state == "nesters_white") || (state == "decision_makers_white"))
        {
            convergence_white += 1;
        }
        else if (state == "black_followers" || state == "black_exploration" || (state == "nesters_black") || (state == "decision_makers_black"))
        {
            convergence_black += 1;
        }
        else
        {
            unassigned += 1;
        }

        m_posFile << "," << i << "," << m_khvec[i]->GetEmbodiedEntity().GetOriginAnchor().Position.GetX() << "," << m_khvec[i]->GetEmbodiedEntity().GetOriginAnchor().Position.GetY() << "," << state;
    }

    if (convergence_white == unRobots || convergence_black == unRobots)
    {
        m_isExperimentFinished = true;
        std::cout << "experiment over ...." << std::endl;
    }
    m_perfFile << "," << m_isExperimentFinished << std::endl;
    m_posFile << "," << m_isExperimentFinished << std::endl;
    }

    if (out_file == "communication_congestion"){

        UInt32 collisions = 0;
        UInt32 conflicts = 0;
        std::string state;
        Real estimate = 0.0f;
        UInt32 convergence_white = 0;
        UInt32 convergence_black = 0;
        UInt32 unassigned = 0;
        UInt32 white_neighbors = 0;
        UInt32 black_neighbors = 0;
        float white_neighbors_ratio = 0.0f;
        float black_neighbors_ratio = 0.0f;
        float white_neighbors_aggregate = 0.0f;
        float black_neighbors_aggregate = 0.0f;
        bool decision_flag = false;

        int zone_collected = 0;

        m_perfFile << GetSpace().GetSimulationClock() << "," << seed << "," << unRobots;
        m_posFile << GetSpace().GetSimulationClock() << "," << seed << "," << unRobots;
        for (int i = 0; i < unRobots; i++)
        {

            buzzvm_t vm = m_buzz_ctrl[i];
            collisions = buzzobj_getint(BuzzGet(vm, "collisions"));
            conflicts = buzzobj_getint(BuzzGet(vm, "conflicts"));
            zone_collected = buzzobj_getint(BuzzGet(vm, "zone_collected"));
            state = buzzobj_getstring(BuzzGet(vm, "BVMSTATE"));
            estimate = buzzobj_getfloat(BuzzGet(vm, "new_belief"));
            white_neighbors_aggregate = buzzobj_getfloat(BuzzGet(vm, "white_ratio"));
            black_neighbors_aggregate = buzzobj_getfloat(BuzzGet(vm, "black_ratio"));
            decision_flag = buzzobj_getint(BuzzGet(vm, "decision_flag"));

        // std::cout<<i<<","<<collisions<<","<<conflicts<<","<<state<<","<<estimate<<","<<white_neighbors_aggregate<<","<<black_neighbors_aggregate<<","<<decision_flag<<std::endl;

        m_perfFile << "," << i << "," << collisions << "," << conflicts << "," << state << "," << estimate << "," << white_neighbors_aggregate << "," << black_neighbors_aggregate << "," << decision_flag;
        if (state == "white_exploration" || state == "white_followers" || (state == "nesters_white") || (state == "decision_makers_white"))
        {
            convergence_white += 1;
        }
        else if (state == "black_followers" || state == "black_exploration" || (state == "nesters_black") || (state == "decision_makers_black"))
        {
            convergence_black += 1;
        }
        else
        {
            unassigned += 1;
        }

        m_posFile << "," << i << "," << m_khvec[i]->GetEmbodiedEntity().GetOriginAnchor().Position.GetX() << "," << m_khvec[i]->GetEmbodiedEntity().GetOriginAnchor().Position.GetY() << "," << state;
    }

    if (convergence_white == unRobots || convergence_black == unRobots)
    {
        m_isExperimentFinished = true;
        std::cout << "experiment over ...." << std::endl;
    }
    m_perfFile << "," << m_isExperimentFinished << std::endl;
    m_posFile << "," << m_isExperimentFinished << std::endl;

    }

    if (out_file == "divison_labour"){
        UInt32 collisions = 0;
        UInt32 conflicts = 0;
        std::string state;
        Real estimate = 0.0f;
        UInt32 belief = 0;
        UInt32 convergence_white = 0;
        UInt32 convergence_black = 0;
        UInt32 unassigned = 0;
        UInt32 white_neighbors = 0;
        UInt32 black_neighbors = 0;
        float white_neighbors_ratio = 0.0f;
        float black_neighbors_ratio = 0.0f;
        float white_neighbors_aggregate = 0.0f;
        float black_neighbors_aggregate = 0.0f;
        bool decision_flag = false;

        std::string zone_collected;

        m_perfFile << GetSpace().GetSimulationClock() << "," << seed << "," << unRobots;
        m_posFile << GetSpace().GetSimulationClock() << "," << seed << "," << unRobots;
        for (int i = 0; i < unRobots; i++)
        {

            buzzvm_t vm = m_buzz_ctrl[i];
            collisions = buzzobj_getint(BuzzGet(vm, "collisions"));
            conflicts = buzzobj_getint(BuzzGet(vm, "conflicts"));
            zone_collected = buzzobj_getstring(BuzzGet(vm, "zone_assigned"));
            belief = buzzobj_getint(BuzzGet(vm, "belief"));
            estimate = buzzobj_getfloat(BuzzGet(vm, "new_belief"));
            white_neighbors_aggregate = buzzobj_getfloat(BuzzGet(vm, "others_belief_white"));
            black_neighbors_aggregate = buzzobj_getfloat(BuzzGet(vm, "others_belief_black"));

        // std::cout<<i<<","<<collisions<<","<<conflicts<<","<<state<<","<<estimate<<","<<white_neighbors_aggregate<<","<<black_neighbors_aggregate<<","<<decision_flag<<std::endl;

        m_perfFile << "," << i << "," << collisions << "," << conflicts << "," << belief << "," << estimate << "," << white_neighbors_aggregate << "," << black_neighbors_aggregate << "," << zone_collected;
        if (belief == 1)
        {
            convergence_white += 1;
        }
        else if (belief == -1)
        {
            convergence_black += 1;
        }
        else
        {
            unassigned += 1;
        }

        m_posFile << "," << i << "," << m_khvec[i]->GetEmbodiedEntity().GetOriginAnchor().Position.GetX() << "," << m_khvec[i]->GetEmbodiedEntity().GetOriginAnchor().Position.GetY();
    }

    // std::cout << "white convergence: " << convergence_white << std::endl;

    if (convergence_white == unRobots || convergence_black == unRobots)
    {
        m_isExperimentFinished = true;
        std::cout << "experiment over ...." << std::endl;
    }
    m_perfFile << "," << m_isExperimentFinished << std::endl;
    m_posFile << "," << m_isExperimentFinished << std::endl;


    }


}

void DDMKheperaLoopFunction::Reset()
{
    OpenFile(m_perfFile, PERF_PREFIX);
    OpenFile(m_posFile, POSTITIONFILE_PREFIX);
}

void DDMKheperaLoopFunction::Destroy()
{
    m_isExperimentFinished = false;

    CloseFile(m_posFile);
    CloseFile(m_perfFile);
}

bool DDMKheperaLoopFunction::IsExperimentFinished()
{
    return m_isExperimentFinished;
}

void DDMKheperaLoopFunction::OpenFile(std::ofstream &c_stream,
                                      const std::string &str_prefix)
{
    /* Make filename */
    std::string strFName = dir + str_prefix + m_strOutFile;
    /* Close file and reopen it */
    CloseFile(c_stream);
    c_stream.open(strFName.c_str(),
                  std::ofstream::out | std::ofstream::trunc);
    if (c_stream.fail())
        THROW_ARGOSEXCEPTION("Error opening \"" << strFName << "\": " << strerror(errno));
}

/***************************************/
/****************************************/

void DDMKheperaLoopFunction::CloseFile(std::ofstream &c_stream)
{
    if (c_stream.is_open())
        c_stream.close();
}

CColor DDMKheperaLoopFunction::GetFloorColor(const CVector2 &c_position_on_plane)
{
    m_frange = m_pcRNG->Uniform(CRange<Real>(0.0f, 1.0f));

    if (c_position_on_plane.GetY() <= -1.0f and c_position_on_plane.GetY() >= -2.0f)
    {
        if (m_frange > fill_ratio_black)
        {
            return CColor::WHITE;
        }
        else
        {
            return CColor::BLACK;
        }
    }

    else if (c_position_on_plane.GetY() >= 1.0f and c_position_on_plane.GetY() <= 2.0f)
    {
        if (m_frange > fill_ratio_white)
        {
            return CColor::WHITE;
        }
        else
        {
            return CColor::BLACK;
        }
    }

    return CColor::GRAY50;
}

void DDMKheperaLoopFunction::PlaceUniformly(UInt32 un_robots,
                                            UInt32 un_data_size,
                                            Real rab_range,
                                            Real rab_range_beacon)
{

    UInt32 unTrials;
    CKheperaIVEntity *pcKH;
    std::ostringstream cKHId;
    CVector3 cKHPos;
    CQuaternion cKHRot;
    /* Create a RNG (it is automatically disposed of by ARGoS) */

    //   /* For each robot */
    for (size_t i = 0; i < un_robots; ++i)
    {
        //     /* Make the id */
        cKHId.str("");
        cKHId << "kh" << i;
        //     /* Create the robot in the origin and add it to ARGoS space */
        pcKH = new CKheperaIVEntity(
            cKHId.str(),
            KH_CONTROLLER,
            CVector3(),
            CQuaternion(),
            rab_range,
            un_data_size);
        AddEntity(*pcKH);
        //     /* Add its controller to the list */
        m_vecControllers.push_back(
            &dynamic_cast<CBuzzControllerKheperaIV &>(
                pcKH->GetControllableEntity().GetController()));
        m_khvec.push_back(pcKH);

        buzzvm_t tBuzzVM = m_vecControllers[i]->GetBuzzVM();
        m_buzz_ctrl.push_back(tBuzzVM);

        //     /* Try to place it in the arena */
        unTrials = 0;
        bool bDone;
        do
        {
            /* Choose a random position */
            ++unTrials;

            CRange<Real> c_range_x(-1.9f, 1.9f);
            CRange<Real> c_range_y(-0.9f, 0.9f);

            cKHPos.Set(m_pcRNG->Uniform(c_range_x),
                       m_pcRNG->Uniform(c_range_y),
                       0.0f);

            cKHRot.FromAngleAxis(m_pcRNG->Uniform(CRadians::UNSIGNED_RANGE),
                                 CVector3::Z);
            bDone = MoveEntity(pcKH->GetEmbodiedEntity(), cKHPos, cKHRot);

        } while (!bDone && unTrials <= MAX_PLACE_TRIALS);
        if (!bDone)
        {
            THROW_ARGOSEXCEPTION("Can't place " << cKHId.str());
        }
    }

    bool bDone;
    for (size_t i = 0; i < 10; ++i)
    {

        cKHId.str("");
        cKHId << "kh" << i + 120;
        //      /* Create the robot in the origin and add it to ARGoS space */
        pcKH = new CKheperaIVEntity(
            cKHId.str(),
            KH_CONTROLLER,
            CVector3(),
            CQuaternion(),
            rab_range_beacon,
            un_data_size);
        AddEntity(*pcKH);
        //     /* Add its controller to the list */
        m_vecControllers.push_back(
            &dynamic_cast<CBuzzControllerKheperaIV &>(
                pcKH->GetControllableEntity().GetController()));
        m_khvec.push_back(pcKH);

        buzzvm_t tBuzzVM = m_vecControllers[i + un_robots]->GetBuzzVM();
        m_buzz_ctrl.push_back(tBuzzVM);

        if (i < 5)
        {

            cKHPos.Set(i * 0.9f - 1.8f,
                       2.2f,
                       0.0f);

            cKHRot.FromAngleAxis(-1 * CRadians::PI_OVER_TWO,
                                 CVector3::Z);
        }

        else if (i >= 5)
        {

            cKHPos.Set((i - 5) * 0.9f - 1.8f,
                       -2.2f,
                       0.0f);

            cKHRot.FromAngleAxis(CRadians::PI_OVER_TWO,
                                 CVector3::Z);
        }

        bDone = MoveEntity(pcKH->GetEmbodiedEntity(), cKHPos, cKHRot);
    }
}


void DDMKheperaLoopFunction::PlaceUniformlyZones(UInt32 un_robots,
                                            UInt32 un_data_size,
                                            Real rab_range,
                                            Real rab_range_beacon)
{

    UInt32 unTrials;
    CKheperaIVEntity *pcKH;
    std::ostringstream cKHId;
    CVector3 cKHPos;
    CQuaternion cKHRot;
    /* Create a RNG (it is automatically disposed of by ARGoS) */

    //   /* For each robot */
    for (size_t i = 0; i < un_robots; ++i)
    {
        //     /* Make the id */
        cKHId.str("");
        cKHId << "kh" << i;
        //     /* Create the robot in the origin and add it to ARGoS space */
        pcKH = new CKheperaIVEntity(
            cKHId.str(),
            KH_CONTROLLER,
            CVector3(),
            CQuaternion(),
            rab_range,
            un_data_size);
        AddEntity(*pcKH);
        //     /* Add its controller to the list */
        m_vecControllers.push_back(
            &dynamic_cast<CBuzzControllerKheperaIV &>(
                pcKH->GetControllableEntity().GetController()));
        m_khvec.push_back(pcKH);

        buzzvm_t tBuzzVM = m_vecControllers[i]->GetBuzzVM();
        m_buzz_ctrl.push_back(tBuzzVM);

        //     /* Try to place it in the arena */
        unTrials = 0;
        bool bDone;
        do
        {
            /* Choose a random position */
            ++unTrials;

            if (i < un_robots/3){
                CRange<Real> c_range_x(-1.9f, 1.9f);
                CRange<Real> c_range_y(-1.9f, -1.1f);
                cKHPos.Set(m_pcRNG->Uniform(c_range_x),
                       m_pcRNG->Uniform(c_range_y),
                       0.0f);
            }

            if (i >= un_robots/3 && i < 2*un_robots/3){
                CRange<Real> c_range_x(-1.9f, 1.9f);
                CRange<Real> c_range_y(-0.9f, 0.9f);
                cKHPos.Set(m_pcRNG->Uniform(c_range_x),
                       m_pcRNG->Uniform(c_range_y),
                       0.0f);
            }

            if (i >= 2*un_robots/3){
                CRange<Real> c_range_x(-1.9f, 1.9f);
                CRange<Real> c_range_y(1.1f, 1.9f);
                cKHPos.Set(m_pcRNG->Uniform(c_range_x),
                       m_pcRNG->Uniform(c_range_y),
                       0.0f);
            }



            cKHRot.FromAngleAxis(m_pcRNG->Uniform(CRadians::UNSIGNED_RANGE),
                                 CVector3::Z);
            bDone = MoveEntity(pcKH->GetEmbodiedEntity(), cKHPos, cKHRot);

        } while (!bDone && unTrials <= MAX_PLACE_TRIALS);
        if (!bDone)
        {
            THROW_ARGOSEXCEPTION("Can't place " << cKHId.str());
        }
    }

    
    for (size_t i = 0; i < 10; ++i)
    {

        cKHId.str("");
        cKHId << "kh" << i + 120;
        //      /* Create the robot in the origin and add it to ARGoS space */
        pcKH = new CKheperaIVEntity(
            cKHId.str(),
            KH_CONTROLLER,
            CVector3(),
            CQuaternion(),
            rab_range_beacon,
            un_data_size);
        AddEntity(*pcKH);
        //     /* Add its controller to the list */
        m_vecControllers.push_back(
            &dynamic_cast<CBuzzControllerKheperaIV &>(
                pcKH->GetControllableEntity().GetController()));
        m_khvec.push_back(pcKH);

        buzzvm_t tBuzzVM = m_vecControllers[i + un_robots]->GetBuzzVM();
        m_buzz_ctrl.push_back(tBuzzVM);
        bool bDone;
        if (i < 5)
        {

            cKHPos.Set(i * 0.9f - 1.8f,
                       2.2f,
                       0.0f);

            cKHRot.FromAngleAxis(-1 * CRadians::PI_OVER_TWO,
                                 CVector3::Z);
        }

        else if (i >= 5)
        {

            cKHPos.Set((i - 5) * 0.9f - 1.8f,
                       -2.2f,
                       0.0f);

            cKHRot.FromAngleAxis(CRadians::PI_OVER_TWO,
                                 CVector3::Z);
        }

        bDone = MoveEntity(pcKH->GetEmbodiedEntity(), cKHPos, cKHRot);
    }
}



REGISTER_LOOP_FUNCTIONS(DDMKheperaLoopFunction, "DDM_khepera_loop_function")