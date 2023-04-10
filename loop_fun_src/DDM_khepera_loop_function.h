#include <argos3/core/simulator/loop_functions.h>
#include <argos3/plugins/robots/kheperaiv/control_interface/buzz_controller_kheperaiv.h>
#include <argos3/plugins/robots/kheperaiv/simulator/kheperaiv_entity.h>
#include <argos3/core/simulator/entity/floor_entity.h>
#include <buzz/argos/buzz_loop_functions.h>
#include <buzz/buzzvm.h>
#include <buzz/buzztype.h>
#include <fstream>
#include <string>
#include <cerrno>
#include "buzz_utils.h"

using namespace argos;

class DDMKheperaLoopFunction : public CLoopFunctions {

public:

    // Planningloop();
    // virtual ~Planningloop();

    virtual void Init(TConfigurationNode& t_tree);
    virtual void PostStep();
    
    virtual void PlaceUniformly(UInt32 un_robots,
                       UInt32 un_data_size);

    virtual CColor GetFloorColor(const CVector2& c_position_on_plane);

    virtual void Reset();
    virtual void Destroy();
    virtual bool IsExperimentFinished();

private:

    bool m_isExperimentFinished = false;
    bool m_istreeExperimentFinished = false;
    int seed;

    UInt32 unRobots;
    Real RAB_RANGE;

    std::vector<buzzvm_t> m_buzz_ctrl;
    std::vector<CBuzzControllerKheperaIV*> m_vecControllers;
    std::vector<CKheperaIVEntity*> m_khvec;

    void OpenFile(std::ofstream& c_stream,
                 const std::string& str_prefix);
    
    void CloseFile(std::ofstream& c_stream);

    std::string m_strOutFile;
    std::string dir;
    int type;
    std::ofstream m_posFile;
    std::ofstream m_perfFile;

    float fill_ratio_a = 0.5;
    float fill_ratio_b = 0.5;

    CRandom::CRNG* m_pcRNG;

    Real m_frange;

    CFloorEntity* m_pcFloor;



};