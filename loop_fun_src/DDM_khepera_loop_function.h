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
                                UInt32 un_data_size, 
                                Real rab_range,
                                Real rab_range_beacon
                                );

    virtual CColor GetFloorColor(const CVector2& c_position_on_plane);

    virtual void Reset();
    virtual void Destroy();
    virtual bool IsExperimentFinished();

private:

    bool m_isExperimentFinished = false;
    
    int seed;

    UInt32 unRobots;
    UInt32 unDataSize;
    Real rab_range;
    Real rab_range_beacon;

    std::vector<buzzvm_t> m_buzz_ctrl;
    std::vector<CBuzzControllerKheperaIV*> m_vecControllers;
    std::vector<CKheperaIVEntity*> m_khvec;

    void OpenFile(std::ofstream& c_stream,
                 const std::string& str_prefix);
    
    void CloseFile(std::ofstream& c_stream);

    std::string m_strOutFile;
    std::string dir;
    std::string out_file;
    std::ofstream m_posFile;
    std::ofstream m_perfFile;

    Real fill_ratio_white = 0.5;
    Real fill_ratio_black = 0.5;

    CRandom::CRNG* m_pcRNG;

    Real m_frange;

    CFloorEntity* m_pcFloor;



};