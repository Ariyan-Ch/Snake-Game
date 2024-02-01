const char title[] = "Middle Finger Snake :)";


const int M = 20;   
const int N = 20;   
const int O = M*N;

int gameGrid[M][N] = {0};


int head[2]={5,3}, point_2[2];
int body[O][2], body2[O][2];
int bodyStop;
int food[2]={rand()%N,rand()%M}; 
int scoreNum=0; 
float delay=0.2;
bool death=false;
