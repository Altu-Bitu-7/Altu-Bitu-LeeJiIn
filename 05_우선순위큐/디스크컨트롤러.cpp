#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct sortByMinTime {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1]; // 최소힙
    }  
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int curr_time = 0; // 현재 시간
    int total_time = 0; // 대기 시간
    int next_job = 0;
    int job_cnt = jobs.size();
    
    // 소요시간이 작은 task가 top이 되는 우선순위큐
    priority_queue<vector<int>, vector<vector<int>>, sortByMinTime> pq;
    
    sort(jobs.begin(), jobs.end()); // 요청시간 순으로 sort
    
    while (next_job < job_cnt || !pq.empty()) {
        // 현재 요청된 task가 없지만 task가 남아있는 경우
        if (pq.empty()) {
            curr_time = jobs[next_job][0]; // 현재시간을 가장 빠른 task의 요청시간으로 변경
            pq.push(jobs[next_job++]);
        }
        
        // 현재 요청된 task 중 소요시간이 가장 빠른 task 수행
        vector<int> curr_job = pq.top();
        pq.pop();
        
        total_time += ((curr_time - curr_job[0]) + curr_job[1]); // delay + 소요시간
        curr_time += curr_job[1];
        
        // 현재 시간까지 요청된 task를 pq에 삽입
        while (next_job < job_cnt && jobs[next_job][0] <= curr_time) {
            pq.push(jobs[next_job++]);
        }
    }
    answer = int(total_time / job_cnt);
    
    return answer;
}