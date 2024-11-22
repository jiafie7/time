#include "utility/time.h"

using namespace melon::utility;

Time::Time()
{
  time_t ticks = time(nullptr);
  getLocalTime(&m_tm, &ticks);

  struct timeval tv = {0};
  getTimeofDay(&tv);
  m_sec = tv.tv_sec;
  m_usec = tv.tv_usec;
}

void Time::getLocalTime(struct tm* tm, const time_t* ticks)
{
#ifdef WIN32
  localtime_s(tm, ticks);
#else
  localtime_r(ticks, tm);
#endif
}

void Time::getTimeofDay(struct timeval* tv)
{
#ifdef WIN32
  SYSTEMTIME wtm;
  GetLocalTime(&wtm);
  struct tm tm;
  tm.tm_year = wtm.mYear - 1900;
  tm.tm_mon = wtm.mMonth - 1;
  tm.tm_mday = wtm.wDay;
  tm.tm_hour = wtm.wHour;
  tm.tm_min = wtm.wMinute;
  tm.tm_sec = wtm.wSecond;
  tm.tm_isdst = -1;

  time_t ticks = mktime(&tm);
  tv->tv_sec = ticks;
  tv->tv_usec = wtm.wMilliseconds * 1000;
#else
  gettimeofday(tv, nullptr);
#endif
}

int Time::getYear() const
{
  return m_tm.tm_year + 1900;
}
       
int Time::getMonth() const
{
  return m_tm.tm_mon + 1;
}
        
int Time::getDay() const
{
  return m_tm.tm_mday;
}
        
int Time::getHour() const
{
  return m_tm.tm_hour;
}
        
int Time::getMinute() const
{
  return m_tm.tm_min;
}
        
int Time::getSecond() const
{
  return m_tm.tm_sec;
}
        
int Time::getWeek() const
{
  return m_tm.tm_wday;
}

double Time::seconds() const
{
  return m_sec;
}
       
double Time::milliseconds() const
{
  return m_sec * 1000.0 + m_usec / 1000.0;
}

double Time::operator-(const Time& other)
{
  return (m_sec - other.m_sec) * 1000 * 1000 + (m_usec - other.m_usec);
}

void Time::setSleep(int milliseconds)
{
#ifdef WIN32
  Sleep(milliseconds);
#else
  usleep(milliseconds * 1000);
#endif
}

std::string Time::format(const std::string& format) const
{
  char timestamp[32] = {0};
  strftime(timestamp, sizeof(timestamp), format.c_str(), &m_tm);
  return timestamp;
}




