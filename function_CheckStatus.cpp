
int CheckStatus(char chess[10]){
	int Status=0;
	if(chess[0]==chess[3]&&chess[3]==chess[6]||chess[1]==chess[4]&&chess[4]==chess[7]||chess[2]==chess[5]&&chess[8]==chess[5])
    Status=1;
	else if(chess[0]==chess[1]&&chess[1]==chess[2]||chess[3]==chess[4]&&chess[4]==chess[5]||chess[6]==chess[7]&&chess[7]==chess[8])
    Status=1;
    else if(chess[0]==chess[4]&&chess[4]==chess[8]||chess[2]==chess[4]&&chess[4]==chess[6])
    Status=1;
	else Status=0;
    return Status;
}