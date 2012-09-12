#include<cstdio>
int humble[6000];
int main(){
	int t2,t3,t5,t7,p2,p3,p5,p7,i,min;
	p2 = p3 = p5 = p7 = 1;
	humble[1] = 1;
	for(i = 1;i < 5843;i ++){
		t2 = humble[p2] * 2;
		t3 = humble[p3] * 3;
		t5 = humble[p5] * 5;
		t7 = humble[p7] * 7;
		min = t2 < t3 ? t2 : t3;
		min = min < t5 ? min : t5;
		min = min < t7 ? min : t7;
		humble[i+1] = min;
		if(min == t2)p2 ++;
		if(min == t3)p3 ++;
		if(min == t5)p5 ++;
		if(min == t7)p7 ++;
	}
	while(scanf("%d",&i) && i){
		if(i % 10 == 1){
			if(i % 100 == 11)printf("The %dth humble number is %d.\n",i,humble[i]);
			else printf("The %dst humble number is %d.\n",i,humble[i]);
			continue;
		}
		if(i % 10 == 2){
			if(i % 100 == 12)printf("The %dth humble number is %d.\n",i,humble[i]);
			else printf("The %dnd humble number is %d.\n",i,humble[i]);
			continue;
		}
		if(i % 10 == 3){
			if(i % 100 == 13)printf("The %dth humble number is %d.\n",i,humble[i]);
			else printf("The %drd humble number is %d.\n",i,humble[i]);
			continue;
		}
		else printf("The %dth humble number is %d.\n",i,humble[i]);
	}
	return 0;
}