#include"headerFile.h"

int main(int argc,char **argv) 

{
	int limit,j=2;
	char *fileName;
	fileName = (char*)malloc(sizeof(char));
	  FILE *fp;
  strcpy(fileName ,"Points.txt");
  fp = fopen(fileName,"w+");
	
	
  float *xValues,*yValues ;
	limit = atoi(argv[1]);
	xValues = (float*)malloc(sizeof(float)*limit);
	yValues = (float*)malloc(sizeof(float)*limit);
	for(int i=0;i<limit;i++)
		xValues[i] = atof(argv[j++]);

	for(int i=0;i<limit;i++)
		yValues[i] = atof(argv[j++]);

	
		
  	
	
	 	
	int count = (atoi(argv[1]));
	int i=1,no,lineC=0,pointC=0;
	no = 12;

	VoronoiDiagramGenerator vdg;
	vdg.generateVoronoi(xValues,yValues,count, -500,500,-500,500,3);
		

	vdg.resetIterator();

	float x1,y1,x2,y2;

	
	while(vdg.getNext(x1,y1,x2,y2))
	{
		printf("%f %f -> %f %f \n",x1,y1,x2,y2);
		fprintf(fp,"\n%f\t%f\t%f\t%f",x1,y1,x2,y2);
		
	}
		
	fclose(fp);
	getLines(fileName);
	return 0;
}
