#define MAX_FRAMES 10

/******************************************************/
typedef enum
{
	OPEN,
	SPARE,
	STRIKE
}gamestate;

typedef struct str_frame
{
	uint8_t roll1;
	uint8_t roll2;
	uint16_t score;
	gamestate frameState;
}frame;
/************************************************************/
void update_score(frame *updateFrame)
{
	updateFrame->score = updateFrame->roll1 + updateFrame->roll2;
}
/**********************************************************/
void print_score(gamestate frameState, uint8_t frameNumber, uint16_t score)
{
	switch(frameState)
	{
		case STRIKE:
		{
			printf("Frame: %d Strike. Score: %d\n",frameNumber + 1,score);
			break;
		}
		case SPARE:
		{
			printf("Frame: %d Spare. Score: %d\n",frameNumber + 1, score);
			break;
		}
		case OPEN:
		{
			printf("Frame: %d. Score: %d\n",frameNumber + 1,score);
			break;
		}
		default:
		{
			
		}
	}
	if(score == 300)
	{
		printf("Congratulations! A prefect game! \n");
	}
}
/**** init_frams 
***** purpose: set all the values for the frame structs to 0
****/
void init_frames(frame *ptrFrames)
{
	uint8_t i = 1;
	
	while(i <= MAX_FRAMES)
	{
		ptrFrames->score = 0;
		ptrFrames->roll1 = 0;
		ptrFrames->roll2 = 0;
		ptrFrames->frameState = OPEN;
		i++;
	}
}
