#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

class Time
{
public:
    // Constructors
    Time();
    Time(unsigned hour, unsigned minutes);

    // Set
    void SetHour(unsigned hour);
    void SetMins(unsigned mins);

    // Get
    unsigned GetHour()      const;
    unsigned GetMins()      const;
    bool     GetValidity()  const;

    // Helper Methods
    bool IsValid() const;

private:
    unsigned m_hour;
    unsigned m_mins;
    bool     m_valid;
};

#endif // TIME_H_INCLUDED
