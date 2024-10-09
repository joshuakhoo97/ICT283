#include "Time.h"

// Constructors

Time::Time() : m_hour(), m_mins() , m_valid(false){}

Time::Time(unsigned hour, unsigned mins)
    : m_hour(hour), m_mins(mins), m_valid(IsValid()) {}

// Get
unsigned Time::GetHour() const
{
    return m_hour;
}

unsigned Time::GetMins() const
{
    return m_mins;
}

bool Time::GetValidity() const
{
    return m_valid;
}

// Set
void Time::SetHour(unsigned hour)
{
    m_hour = hour;
    m_valid = IsValid();
}

void Time::SetMins(unsigned mins)
{
    m_mins = mins;
    m_valid = IsValid();
}

// Helper Methods
bool Time::IsValid() const
{
    return (m_hour >= 0 && m_hour <=23) && (m_mins >= 0 && m_mins <= 59);
}

