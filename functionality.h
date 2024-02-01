void snake(float& timer, int& delta_x, bool& spawn){

	if (timer>delay){
	
	//--------stores the previous location of the body block--------//	
		point_2[0]=head[0];
		point_2[1]=head[1];
		for(int i=0;i<O;i++)
		{
			if(i>bodyStop)
				break;
			else if(i==0)
				continue;
			
			body2[i][0]=body[i-1][0];
			body2[i][1]=body[i-1][1];
		}
	//--------stores the previous location of the body block--------//
		
		
	//-----------//---------- smoves the head ----------//----------//
		if(delta_x==-2){
			head[1]+=1;			//down
			
		}
		else if(delta_x==2){	
			head[1]-=1;			//up
			
		}
		else if(delta_x==-1){
			head[0]-=1;			//left
			
		}
		else if(delta_x==1){
			head[0]+=1;			//right
			
		}
	//-----------//---------- smoves the head ----------//----------//
			
	/////moves each part of the body to the location where the next body block was previously/////
	
		for(int i=0;i<O;i++)
		{
			if(i>bodyStop)
				break;
				
			if(i==0){
				body[i][0]=point_2[0];
				body[i][1]=point_2[1];
				continue;
			}
			
			body[i][0]=body2[i][0];
			body[i][1]=body2[i][1];
		}
	/////moves each part of the body to the location where the next body block was previously/////
		
		timer=0;	
				
	}
	
	if(spawn)
	{
		++bodyStop;					//raises the body count. 
		if(delta_x==-2){				//decides which place the spawn the new body block.
			body[bodyStop][0]=body[bodyStop-1][0];
			body[bodyStop][1]=body[bodyStop-1][1]-1;
		}
		else if(delta_x==2){
			body[bodyStop][0]=body[bodyStop-1][0];
			body[bodyStop][1]=body[bodyStop-1][1]+1;
		}
		else if(delta_x==-1){
			body[bodyStop][0]=body[bodyStop-1][0]+1;
			body[bodyStop][1]=body[bodyStop-1][1];
		}
		else if(delta_x==1){
			body[bodyStop][0]=body[bodyStop-1][0]-1;
			body[bodyStop][1]=body[bodyStop-1][1];
		}
		
		spawn=false;
	}
	
	if(head[1]>M-1 || head[1]<0 || head[0]>N-1 || head[0]<0)
		death=true;
}

void gameReset(){

	bodyStop=0;
	for(int i=0;i<O;i++){
	
		for(int j=0;j<2;j++){
			body[i][j]=100;
		}
	}
		
	head[0]=N/2;
	head[1]=M/2;
	body[0][0]=head[0];
	body[0][1]=head[1]-1;
}

void snakeFood(bool& spawn){

	if(head[0]==food[0] && head[1]==food[1])
	{
		scoreNum++;
		spawn = true;
		food[0]=rand()%N;
		food[1]=rand()%M;
	}
	
	if(scoreNum>9)
		delay=0.07;		//fastens the snake.
	else
		delay=0.2;
}












