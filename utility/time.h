#pragma once

#include <ctime>
#include <string>

#ifdef WIN32
#include <windows.h>
#else
#include <sys/time.h>
#include <unistd.h>
#endif

namespace melon
{
  namespace utility
  {
    class Time
    {
      public:
        Time();
        ~Time() = default;

        int getYear() const;
        int getMonth() const;
        int getDay() const;
        int getHour() const;
        int getMinute() const;
        int getSecond() const;
        int getWeek() const;

        double seconds() const;
        double milliseconds() const;

        double operator-(const Time& other);

        static void setSleep(int milliseconds);

        std::string format(const std::string& format) const;

      private:
        void getLocalTime(struct tm* tm, const time_t* ticks);
        void getTimeofDay(struct timeval* tv);

      private:
        struct tm m_tm;
        int m_sec;
        int m_usec;
    };
  }
}
