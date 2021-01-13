#include <chrono> 

template <typename t>

class RunningTime {
  private:
    std::chrono::time_point<std::chrono::system_clock> start, end; 
    std::chrono::duration<double> elapsed_seconds;

  public:
    RunningTime() {
      start = std::chrono::system_clock::now();
    }

    double countDuration() {
      end = std::chrono::system_clock::now();
      elapsed_seconds = end - start;
      t duration = std::chrono::duration_cast<t>(elapsed_seconds);
      return duration.count();
    }
};

// usage example
  // typedef std::chrono::milliseconds t;
  // RunningTime<t> T;
  // cout << test.GetUglyNumber_Solution(1500) << endl; //859963392
  // cout << T.countDuration() << endl;