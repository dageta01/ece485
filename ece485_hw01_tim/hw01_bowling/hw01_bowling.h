#define MAX_FRAMES 10

/******************************************************/
typedef enum
{
	OPEN,
	SPARE,
	STRIKE
}gamestate;

void print_score(gamestate state, uint8_t frameNumber, uint16_t score);

/************************************************************/
void print_score(gamestate state, uint8_t frameNumber, uint16_t score)
{
	switch(state)
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


