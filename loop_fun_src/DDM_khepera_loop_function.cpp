#include "DDM_khepera_loop_function.h"
#include <sstream>
#include <list>
#include <stdlib.h> 
#include <math.h>
#include <cmath>

using namespace argos;


// static std::string POSTITIONFILE_PREFIX   = "pos_";
// static std::string PERF_PREFIX   = "perf_";
// Real RAB_RANGE        = 7.0f;

// static const UInt32 DATA_SIZE = 5000;     
// static const Real        KH_RADIUS        = 0.0704f;
// static const Real        KH_AREA          = ARGOS_PI * Square(0.0704f);
// static const std::string KH_CONTROLLER    = "khivbz";
// static const UInt32      MAX_PLACE_TRIALS = 4000;


void DDMKheperaLoopFunction::Init(TConfigurationNode& t_tree){
    
    // try {
        
    //     GetNodeAttribute(t_tree, "Robots", unRobots);
    //     GetNodeAttribute(t_tree, "rab_range", RAB_RANGE);
    //     GetNodeAttribute(t_tree, "seed", seed);
    //     GetNodeAttribute(t_tree, "dir", dir);
    //     GetNodeAttribute(t_tree, "type", type);
           m_pcFloor = &GetSpace().GetFloorEntity();
           m_pcRNG = CRandom::CreateRNG("argos");
           
      //                        CRANGE_START_POS.GetMax() + Start_state.GetX());
           

        //    for(int i=0; i<int(4*1); i++){
        //    for(int j=0; j<int(4.5*1); j++){
        //        A[i][j] = 0.0;
        //        std::cout << A[i][j] <<" ";
        //     }


    //     std::string OUT_FNAME; 
    //     GetNodeAttribute(t_tree, "out_file", OUT_FNAME);
    //     m_strOutFile = ".txt";
    //     POSTITIONFILE_PREFIX += OUT_FNAME + "_" + std::to_string(unRobots) + "_" + std::to_string(seed);
    //     PERF_PREFIX += OUT_FNAME+ "_" + std::to_string(unRobots) + "_" + std::to_string(seed);
    
    //     float A[unRobots][unRobots];
    //     float pos[unRobots][2];
    //     int B[unRobots][unRobots];
    //     int visit[unRobots];
    //     int edge = 0;
    //     int x = 0;
    //     int y = 0;

    //     // std::cout << "no of robots: " << unRobots << std::endl;
    //     // std::cout << "rab_range: "  << RAB_RANGE << std::endl;
      
    //     PlaceUniformly(unRobots,DATA_SIZE);

    //     for(int i=0; i<m_khvec.size(); i++){
    //         pos[i][0] = m_khvec[i]->GetEmbodiedEntity().GetOriginAnchor().Position.GetX();
    //         pos[i][1] = m_khvec[i]->GetEmbodiedEntity().GetOriginAnchor().Position.GetY();          
    //     }



    //     for(int j=0; j<unRobots; j++){
    //         visit[j] = 0;
    //         for (int k=0; k<unRobots; k++){
    //             B[j][k] = 0;
    //             if ((std::sqrt( std::pow(pos[j][0] - pos[k][0],2) + std::pow(pos[j][1] - pos[k][1],2)) <= RAB_RANGE ) && ( j!=k )){
    //                 A[j][k] = std::sqrt(std::pow(pos[j][0] - pos[k][0],2) + std::pow(pos[j][1] - pos[k][1],2));    
    //             }
    //             else {
    //                 A[j][k] = 0.0;
    //             }
    //         std::cout << A[j][k] <<" ";
    //         }
    //     std::cout << std::endl;
        
    //     }

    //     /* Calculating the minimum spanning tree of the robots. */
    //     visit[0] = true;
    //     while (edge < unRobots - 1) {
    //         int min = 1000;
    //         // std::cout << edge << std::endl;
    //         for (int i = 0; i < unRobots; i++) {
    //             if (visit[i]==1) {
    //                 for (int j = 0; j < unRobots; j++) {
    //                     if ((visit[j]==0) && (A[i][j] > 0)) { 
    //                         if (min > A[i][j]) {
    //                             min = A[i][j];
    //                             x = i;
    //                             y = j;
    //                         }
    //                     }
    //                 }
    //             }
    //         }
    //     B[x][y] = 1;
    //     B[y][x] = 1;
    //     std::cout << x <<  " ---> " << y;
    //     std::cout << std::endl;
    //     visit[y] = 1;
    //     edge = edge + 1;
    //     }

    //     for(int j=0; j<unRobots; j++){
    //         for (int k=0; k<unRobots; k++){
    //         std::cout << B[j][k] <<" ";
    //         }
    //     std::cout << std::endl;
    //     }

    //     for(int k=0; k < m_buzz_ctrl.size(); ++k){
    //         buzzvm_t tBuzzVM = m_buzz_ctrl[k];
    //         buzzobj_t spanning_tree = buzzheap_newobj(tBuzzVM, BUZZTYPE_TABLE);
    //         for (int j=0; j<unRobots; j++){
    //             if (B[k][j] == 1){
    //             TablePut(tBuzzVM, spanning_tree, j, 1);
    //             }
    //         }
    //         Register(tBuzzVM, "spanning_tree", spanning_tree);
    //     }
    
    // Reset();
    
    // }
    // catch(CARGoSException& ex) {
    //     THROW_ARGOSEXCEPTION_NESTED("Error initializing the loop functions",ex)
    // }
}

void DDMKheperaLoopFunction::PostStep() {
    
    // int num_neighbours[unRobots]; 
    // float diff[unRobots][2];
    // int B[unRobots][unRobots];
    // float pos[unRobots][2];
    // float A[unRobots][unRobots];
    // int D[unRobots][unRobots];
    // int DA[unRobots][unRobots];
    // Eigen::MatrixXd E(unRobots, unRobots);
    // Eigen::MatrixXd F(unRobots, unRobots);
    // int numones = 0;
    // int numtwoes = 0;
    // int x = 0;


    
    // for(int i=0; i<m_khvec.size(); i++){
    //         pos[i][0] = m_khvec[i]->GetEmbodiedEntity().GetOriginAnchor().Position.GetX();
    //         pos[i][1] = m_khvec[i]->GetEmbodiedEntity().GetOriginAnchor().Position.GetY();          
    // }
    

    // for(int j=0; j<unRobots; j++){
    //         int ctr = 0;
    //         for (int k=0; k<unRobots; k++){
    //             B[j][k] = 0;
    //             D[j][k] = 0;
    //             DA[j][k] = 0;
    //             if ((std::sqrt( std::pow(pos[j][0] - pos[k][0],2) + std::pow(pos[j][1] - pos[k][1],2)) <= RAB_RANGE ) && ( j!=k )){
    //                 A[j][k] = 1.0;    
    //                 ctr = ctr + 1;
    //             }
    //             else {
    //                 A[j][k] = 0.0;
    //             }
    //         // std::cout << A[j][k] <<" ";
    //         }
    //         DA[j][j] = ctr;
    //     // std::cout << std::endl; 
    // }

    // for(int k=0; k < m_buzz_ctrl.size(); ++k){
    //     buzzvm_t vm = m_buzz_ctrl[k];
    //     BuzzTableOpen(vm, "nei_set_loop_fun");
    //     diff[k][0] = buzzobj_getfloat(BuzzGet(vm,"diff1"));
    //     diff[k][1] = buzzobj_getfloat(BuzzGet(vm,"diff2"));
    //     // std::cout<<" id: "<<k<<" diff1: " << buzzobj_getfloat(BuzzGet(vm,"diff1")) << " diff2: " << buzzobj_getfloat(BuzzGet(vm,"diff2")) << std::endl;
        
    //     int ts = buzzobj_getint(BuzzTableGet(vm, "size"));
    //     // std::cout << "size of neighbour array: " << k << "  " << ts << std::endl;
    //     num_neighbours[k] = ts;
    //     D[k][k] = ts;
    //     for(int32_t i = 0; i < ts ; ++i){
    //         // std::cout << " robot: " << k << " neighbour:  " << buzzobj_getint(BuzzTableGet(vm, i)) << std::endl;
    //         B[k][buzzobj_getint(BuzzTableGet(vm, i))] = 1;
    //     }
    //     BuzzTableClose(vm);
    // }

    
    // for(int j=0; j<unRobots; ++j){
    //     for (int k=0; k<unRobots; ++k){
    //         if (B[j][k] == 1){  
    //             if (A[j][k] == 0){
    //                 B[j][k] = 0;
    //             }
    //         }
    //     }
    // }

    // m_posFile<<GetSpace().GetSimulationClock()<<","<<seed<<","<<unRobots;
    // for (int a=0; a<unRobots;a++){
    //     m_posFile<<","<<a<<","<<pos[a][0]<<","<<pos[a][1];
    //     for (int b=0; b<unRobots;b++){
    //        m_posFile<<","<<B[a][b]; 
    //     } 
    // }
    // m_posFile<<std::endl;
    

    // for(int j=0; j<unRobots; j++){
    //         for (int k=0; k<unRobots; k++){
    //             E(j,k) = D[j][k] - B[j][k];
    //             F(j,k) = DA[j][k] - A[j][k];
    //     }
    // }
    
    // Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> es(E);
    // Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> fs(F);
    
    // if (es.eigenvalues()[1] <= 0)
    // {
    // std::cout << GetSpace().GetSimulationClock()<< std::endl;
    // std::cout << "disconnected: " << std::endl;
    // std::cout << " adjacency matrix: " <<E<< std::endl;
    // std::cout << " eigenvalues: " << std::endl << es.eigenvalues() << std::endl;
    // }

    
    
    // if (type == 0){

    //     /* checking if it is a line in buzz */
    //     for(int j=0; j<unRobots; ++j){
    //         if (num_neighbours[j] == 1){
    //             numones = numones + 1; 
    //         }
    //         else if(num_neighbours[j] == 2){
    //             numtwoes = numtwoes + 1;
    //         }
    //     }
    
    //     if ((numones == 2) && (numtwoes == unRobots - 2) && (!m_istreeExperimentFinished)){
    //         m_istreeExperimentFinished = true;
    //         lambda = es.eigenvalues()[1];
    //         std::cout << "experiment done: " << GetSpace().GetSimulationClock() << std::endl; 
    //     }

    //     if (lambda == fs.eigenvalues()[1]){
    //         m_isExperimentFinished = true;

    //     }

    //     m_perfFile<< GetSpace().GetSimulationClock() << "," << numones << "," << numtwoes << "," << es.eigenvalues()[1] << "," <<fs.eigenvalues()[1] <<","<<m_istreeExperimentFinished<<","<<m_isExperimentFinished << "," <<seed<<","<<unRobots<< std::endl;
    // }

    // if (type == 1){
    //     /* checking if it is a star in buzz */

         
    //     for(int j=0; j<unRobots; ++j){
    //         if (num_neighbours[j] == 1){
    //             numones = numones + 1; 
    //         }
    //         else if(num_neighbours[j] >= 1){
    //             numtwoes = numtwoes + 1;
    //         }
    //     }

    //     std::cout << " Time: "<< GetSpace().GetSimulationClock() << " numones: " << numones << " numtwoes: " << numtwoes << " change: "<< std::lround(es.eigenvalues()[1]) <<std::endl; 
    //     // std::cout << (unRobots - ceil(unRobots/10.0)) << " " << ceil(unRobots/10.0) << std::endl;
        
    //     if ((numones == unRobots-1) && (numtwoes == 1) && (!m_istreeExperimentFinished)){
    //         m_istreeExperimentFinished = true;
    //         // m_isExperimentFinished = true;
    //         lambda = es.eigenvalues()[1];
    //         std::cout << "experiment done: " << GetSpace().GetSimulationClock() ; 
    //     }

    //     if (m_istreeExperimentFinished == true){
    //         bool flag = false;
    //         int time = 0;
    //         for (int k=0;k<unRobots;k++){
    //             if (abs(diff[k][0] - diff[k][1]) > 2) {
    //                 flag = true;
    //             }
    //         }
    //         // std::cout << " " << flag << " "<< std::lround(es.eigenvalues()[1]) <<std::endl;
    //         if ((flag == false) && (std::lround(es.eigenvalues()[1]) == 1)){
    //             m_isExperimentFinished = true;
    //         }
    //     }

    //     m_perfFile<< GetSpace().GetSimulationClock() << "," << numones << "," << numtwoes << "," << es.eigenvalues()[1] << "," <<fs.eigenvalues()[1] <<","<<m_istreeExperimentFinished<<","<<m_isExperimentFinished << "," <<seed<<","<<unRobots<< std::endl;


    
    // }

}

void DDMKheperaLoopFunction::Reset(){
    // OpenFile(m_perfFile,PERF_PREFIX);
    // OpenFile(m_posFile,POSTITIONFILE_PREFIX);

}

void DDMKheperaLoopFunction::Destroy(){
    // m_isExperimentFinished = false;
    // m_istreeExperimentFinished = false;
    // CloseFile(m_posFile);
    // CloseFile(m_perfFile);

}

bool DDMKheperaLoopFunction::IsExperimentFinished() {
//    return m_isExperimentFinished;
}

void DDMKheperaLoopFunction::OpenFile(std::ofstream& c_stream,
                      const std::string& str_prefix) {
//    /* Make filename */
//    std::string strFName = dir + str_prefix + m_strOutFile;
//    /* Close file and reopen it */
//    CloseFile(c_stream);
//    c_stream.open(strFName.c_str(),
//                  std::ofstream::out | std::ofstream::trunc);
//    if(c_stream.fail())
//       THROW_ARGOSEXCEPTION("Error opening \"" << strFName << "\": " << strerror(errno));
}

/***************************************/
/****************************************/

void DDMKheperaLoopFunction::CloseFile(std::ofstream& c_stream) {
   if(c_stream.is_open()) c_stream.close();
}

CColor DDMKheperaLoopFunction::GetFloorColor(const CVector2& c_position_on_plane) {
    m_frange = m_pcRNG->Uniform(CRange<Real>(0.0f, 1.0f));
    
    if (c_position_on_plane.GetY() < -1.0f){
        if (m_frange > 0.9){
            return CColor::WHITE;
        }
        else{
            return CColor::BLACK;
        } 
    }

    if (c_position_on_plane.GetY() >= -1.0f && c_position_on_plane.GetY() <= -0.9f){
        return CColor::BLACK;
    }

    if (c_position_on_plane.GetY() >= 0.9f && c_position_on_plane.GetY() <= 1.0f){
        return CColor::WHITE;
    }

    else if (c_position_on_plane.GetY() > 1.0f){
        if (m_frange < 0.9){
            return CColor::WHITE;
        }
        else{
            return CColor::BLACK;
        } 
    }



return CColor::GRAY50;
   
}



void DDMKheperaLoopFunction::PlaceUniformly(UInt32 un_robots,
                                  UInt32 un_data_size) {
    
//     float pos[un_robots][2];
//     UInt32 unTrials;
//     CKheperaIVEntity* pcKH;
//     std::ostringstream cKHId;
//     CVector3 cKHPos;
//     CQuaternion cKHRot;
//     /* Create a RNG (it is automatically disposed of by ARGoS) */
//     CRandom::CRNG* pcRNG = CRandom::CreateRNG("argos");
// //   /* For each robot */
//     for (size_t i = 0; i < un_robots; ++i) {
// //     /* Make the id */
//        cKHId.str("");
//        cKHId << "kh" << i;
// //     /* Create the robot in the origin and add it to ARGoS space */
//        pcKH = new CKheperaIVEntity(
//                   cKHId.str(),
//                   KH_CONTROLLER,
//                   CVector3(),
//                   CQuaternion(),
//                   RAB_RANGE,
//                   un_data_size);
//         AddEntity(*pcKH);
// //     /* Add its controller to the list */
//        m_vecControllers.push_back(
//                   &dynamic_cast<CBuzzControllerKheperaIV&>(
//                   pcKH->GetControllableEntity().GetController()));
//        m_khvec.push_back(pcKH);
       
//        buzzvm_t tBuzzVM = m_vecControllers[i]->GetBuzzVM();
//        m_buzz_ctrl.push_back(tBuzzVM);

// //     /* Try to place it in the arena */
//        unTrials = 0;
//        bool bDone;
//        do {
//             /* Choose a random position */
//             ++unTrials;
//             if (i == 0){
//                 cKHPos.Set(0.0f,
//                            0.0f,
//                            0.0f);
//                 pos[0][0] = 0.0;
//                 pos[0][1] = 0.0;
//             }      

//             if (i>0){
//                 int rid = rand() % i;
//                 Real r = 0;
//                 CRadians theta;
//                 CRange<Real> c_range_x(0.67*RAB_RANGE, 0.90*RAB_RANGE);
//                 r = pcRNG->Uniform(c_range_x);
//                 theta = pcRNG->Uniform(CRadians::UNSIGNED_RANGE);
                
//                 pos[i][0] = pos[rid][0] + r*Cos(theta);
//                 pos[i][1] = pos[rid][1] + r*Sin(theta);

//                 cKHPos.Set(pos[i][0],
//                            pos[i][1],
//                            0.0f);
//             }
      
//             cKHRot.FromAngleAxis(pcRNG->Uniform(CRadians::UNSIGNED_RANGE),
//                            CVector3::Z);
//             bDone = MoveEntity(pcKH->GetEmbodiedEntity(), cKHPos, cKHRot);
        
//         } while (!bDone && unTrials <= MAX_PLACE_TRIALS);
//         if (!bDone) {
//             THROW_ARGOSEXCEPTION("Can't place " << cKHId.str());
//         }
//         }
}




REGISTER_LOOP_FUNCTIONS(DDMKheperaLoopFunction, "DDM_khepera_loop_function")