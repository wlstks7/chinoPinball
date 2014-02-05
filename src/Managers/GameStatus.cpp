#include "GameStatus.h"

// SINGLETON initalizations
bool GameStatus::instanceFlag = false;
GameStatus* GameStatus::single = NULL;

//--------------------------------------
GameStatus::GameStatus(void){
	idPlayer = 0;
	currentMission = 0;
	score = 0;
    lives = NO_OF_LIVES;
    status = WAITING_NEW_PLAYER;
}

//--------------------------------------
GameStatus* GameStatus::getInstance(void){
	if(! instanceFlag)
		{
			single = new GameStatus();
			instanceFlag = true;
			return single;
		}else{
			return single;
		}
}

//--------------------------------------
void GameStatus::NewPlayer(void){
	idPlayer += 1;
	score = 0;
    status = SETTING_UP_THE_GAME;
    
}

//---------------------------------------
void GameStatus::saveRanking(void){

}

//---------------------------------------
bool GameStatus::StartMission(){
	bool missions_left;

	if (currentMission <= NO_OF_MISSIONS ){
		currentMission += 1;
		lives = NO_OF_LIVES;
		missions_left = true;
        status = WAITING_START_PLAY;
	}
	else{
		lives = -1;
		currentMission = 0xFFFF;
		missions_left = false;
        status = WAITING_NEW_PLAYER;
	}

	return missions_left;

}

//--------------------------------------
void GameStatus::EndMission(){
	lives = -1;

}

//--------------------------------------
void GameStatus::AddPoints(int points){
    score += points;
}
//------------------------------------
bool GameStatus::Play(void){
    status = PLAYING;
}
//-------------------------------------
bool GameStatus::Death(){
	bool dead;
	if (lives !=0 ){
		lives -= 1;
		dead = false;
	}
	else{
		lives = -1;
		dead = true;
	}

	return dead;
}

//---------------------------------------
int GameStatus::GetRemainingLifes(void){
	return lives;
}

//-----------------------------------------
int GameStatus::GetRemainingMissions(void){
	return NO_OF_MISSIONS - currentMission;
}

//----------------------------------------
int GameStatus::GetPlayerId(void){
	return idPlayer;
}

//----------------------------------------
GameStatus::enGameStatus GameStatus::GetGameStatus(void){
    return status;
}

//----------------------------------------
int GameStatus::GetCurrentPlayerScore(void){
    return score;
}
