/*Three Missionaries and three savages across the river
 *m must not less than s on both sides of rivers
 *capacity of boat is two
 *complie this file by running: g++ -o ai ai.cpp
 */

#include <cstdio>
#include <stack>
using namespace std;

int rule[5][2] = {{-2,0}, {0,-2}, {-1,-1}, {-1,0}, {0,-1}};
int state[20][3] = {3,3,1};
int count = 1;

int main(){
	stack<int> s;
	int cur[3] = {3,3,1};   //current state in left
	int i;
	while(count < 20){
		for(i = 0; i < 5; i ++){
			int t0 = cur[0] + rule[i][0] * cur[2];
			int t1 = cur[1] + rule[i][1] * cur[2];
			if(t0 < 0 || t0 > 3 || t1 < 0 || t1 > 3)continue;
			if(t0 == 3 || t0 == 0 || t0 == t1){
				int j;
				for(j = 0; j < count; j ++)
					if(t0 == state[j][0] && t1 == state[j][1] && -cur[2] == state[j][2])break;
				if(j != count)continue;
				
				//change current state and save it
				cur[0] = t0;
				cur[1] = t1;
				cur[2] *= -1;
				state[count][0] = cur[0];
				state[count][1] = cur[1];
				state[count][2] = cur[2];
				count ++;
				s.push(i);
				break;
			}
		}
		if(i == 5){
			count --;
			cur[0] = state[count][0];
		 	cur[1] = state[count][1];
			cur[2] *= -1;
			if(!s.empty())i = s.top();
			s.pop();
			printf("back track\n");
		}
		else i = 0;

		if(cur[0] == 0 && cur[1] == 0 && cur[2] == -1)break;
	}

	for(i = 0; i < count; i ++)
		printf("(%d, %d, %d)\n", state[i][0], state[i][1], state[i][2]);

	return 0;
}
