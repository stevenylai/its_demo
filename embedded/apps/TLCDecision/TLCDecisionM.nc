includes TLCDecision;

module TLCDecisionM{
	provides{
		interface TLCDecision;}
	uses{
//		interface HPLUART as UART;
		interface Tracking;
		interface TrafficLightControl;}
	}

implementation
{	
	TOS_Msg RMsg;
	uint8_t CurrentGreenCase;
			
	uint8_t Nextcase;
	uint8_t Tmax;
	uint8_t Tmin;
	uint8_t Tcontrol;
	uint8_t Gnextcase;
	uint8_t tmp;
	uint8_t speed;
	uint8_t	tmpRM;
	uint8_t	tmpRMIndex;
	uint8_t	Int_Id;
	uint8_t RMlane[4]= {0,0,0,0};
	uint8_t RMcase[2]= {0,0};	
	uint8_t CurrentGreenCase = 2;    
	uint8_t Tmax = 20;    
	uint8_t Tmin = 6;
	uint8_t Gnextcase;
	uint8_t Tcontrol = 10;   
	uint8_t speed = 1; 
	uint16_t TW[2]= {0,0};
//	uint8_t TestUART;	
	
//	Gnextcase = Tmin;
	   		
		command result_t TLCDecision.nextDecision (uint8_t IntId, uint8_t * nextCase, uint8_t * nextCaseLength){			
			uint8_t i;
			uint8_t j;	
			uint8_t color, remain_t;
			
			RMlane[0]= call Tracking.countAllCarsOnIntersection(IntId, 3);
			RMlane[1]= call Tracking.countAllCarsOnIntersection(IntId, 1);
			RMlane[2]= call Tracking.countAllCarsOnIntersection(IntId, 4);
			RMlane[3]= call Tracking.countAllCarsOnIntersection(IntId, 2);

//			TestUART = 0;
//			call UART.put(RMlane[TestUART]);
			
			RMcase[0]=RMlane[0]+RMlane[1];
 			RMcase[1]=RMlane[2]+RMlane[3];
	
			call TrafficLightControl.get(8, &color, &remain_t);
			if (color!=GREEN) {
				CurrentGreenCase = 2;}
			else {CurrentGreenCase = 1;}
			
			Gnextcase = Tmin;
			////////compute RM///////////////
			tmpRMIndex = 0;
			tmpRM = RMcase[tmpRMIndex];
			if (tmpRM < RMcase[1]) {
				tmpRMIndex = 1;
				tmpRM = RMcase[tmpRMIndex];	
			}
			if (tmpRM > 0){
				Nextcase = tmpRMIndex+1;
			}
			else{					
			//	Nextcase = CurrentGreenCase;
			  Nextcase = 3-CurrentGreenCase;	
			}
		////////compute TW/////////////// 	 	
 		for (j=0;j<2;j++){
 			TW[j]= TW[j]+ Gnextcase;
 		}
 		TW[CurrentGreenCase-1]=0;	
 		
		if (TW[0]> (Tmax-Tcontrol) ){
			 if (RMcase[0]>0) { 
					Nextcase = 1;             
				}
				else {
					if (RMcase[1]>0) {Nextcase = 2;}
					else {Nextcase = 1;}
				}
			}
			else {
				if (TW[1]> (Tmax-Tcontrol)){
					if (RMcase[1]>0) { 
						Nextcase = 2;  
					}
					else {
						if (RMcase[0]>0) {Nextcase = 1;}
						else {Nextcase = 2;}
					}
				}
			}							
		////////compute GreenLen///////////////
 		if (Nextcase ==1){	
 			tmp = RMlane[0];
 			if (RMlane[0]<RMlane[1]) {tmp = RMlane[1];}
 			Gnextcase = 6 + tmp/speed;
 		}
 		if (Nextcase ==2){	
 			tmp = RMlane[2];
 			if (RMlane[2]<RMlane[3]) {tmp = RMlane[3];}
 			Gnextcase = 6 + tmp/speed;			
 		}
 		
 		if (Gnextcase < Tmin) {Gnextcase = Tmin;}
 		if (Gnextcase > Tcontrol) {Gnextcase = Tcontrol;}
			
			*nextCase = Nextcase; 
			*nextCaseLength = Gnextcase; 
			return SUCCESS;		
 		}
	
 	event result_t Tracking.carUpdated (Car * currentCar, Car * previousCar) {
 		return SUCCESS;
 	}
 	event result_t TrafficLightControl.lightChanged (uint8_t inter_id, uint8_t color, uint8_t remain_t){
 		return SUCCESS;
 	}
/* 	
 	async event result_t UART.get(uint8_t data) {
		return SUCCESS;
	} 	
 	async event result_t UART.putDone(){
 		TestUART++;
 		if (TestUART<4){call UART.put(RMlane[TestUART]);}
 	}
*/
}
