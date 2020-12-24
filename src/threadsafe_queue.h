#ifndef THREADSAFE_QUEUE_H
#define THREADSAFE_QUEUE_H

#include <mutex>
#include <condition_variable>
#include <queue>
#include <vector>
#include <thread>

//template<typename T>
//class threadsafe_queue
//{
//private:
//    std::mutex mut;
//    std::queue<T> data_queue;
//    std::condition_variable data_cond;
//public:
//    threadsafe_queue(){};
//    void push(T new_value) ;

////    //无限等待
////    int pop(T& value) ;
////    //有限等待
////    int pop_with_timeout(T& value, int timeout);

////    bool is_empty();
//};

template<typename T>
class threadsafe_queue
{
private:
    std::mutex mut;
    std::queue<T> data_queue;
    std::condition_variable data_cond;
public:
    threadsafe_queue(){ }
    void push(T new_value) {
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(new_value);
        data_cond.notify_one();
    }
    //无限等待
    int pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        // (1) 带判断条件的wait, 条件不满足则继续等待; 满足则继续后续代码
        data_cond.wait(lk,[this]{return !data_queue.empty();});
        // (2)wait唤醒后需要再次判断, 避免假唤醒
        //while(true){
        //  data_cond.wait(lk);
        //  if (data_queue.empty())
        //      continue;
        //  else
        //      break;
        //}
        value=data_queue.front();
        data_queue.pop();
        return 0;
    }
    //有限等待
    int pop_with_timeout(T& value, int timeout) {
        if (timeout < 0){
            return this->pop(value);
        }
        std::unique_lock<std::mutex> lk(mut);
        //带超时, 带判断条件的wait
        data_cond.wait_for(lk, std::chrono::milliseconds(timeout), [this] {
               // std::cout << "thread id: " << std::this_thread::get_id() << " wait..." << std::endl;
                return !data_queue.empty();}
        );
        if (!data_queue.empty()){
            value=data_queue.front();
            data_queue.pop();
            return 0;
        }
        return -1;
    }
    bool is_empty(){
        std::lock_guard<std::mutex> lk(mut);
        return data_queue.empty();
    }
};

#endif // THREADSAFE_QUEUE_H
