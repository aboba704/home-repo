#include <iostream>

const int DEFAULT_DATE_DAY = 1;
const int DEFAULT_DATE_MONTH = 1;
const int DEFAULT_DATE_YEAR = 1970;
const int DAYS_IN_YEAR_WITHOUT_FEB = 337;

class Date {
 private:
  int d = DEFAULT_DATE_DAY, m = DEFAULT_DATE_MONTH, y = DEFAULT_DATE_YEAR;
  int days{0};

  int GetDaysInFeb(int year) const {
    if ((!(year % 4) && (year % 100)) || !(year % 400)) {
      return 29;
    }
    return 28;
  }

  int GetDaysInMonth(int month, int year) const {
    switch (month) {
      case 2:
        return GetDaysInFeb(year);
      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12:
        return 31;
      default:
        return 30;
    }
  }

  int GetDaysInYear(int year) const { return DAYS_IN_YEAR_WITHOUT_FEB; }

  bool IsCorrectDate() const {
    return GetMonth() <= 12 && GetMonth() >= 1 && GetDay() >= 0 &&
           GetDay() <= GetDaysInMonth(GetMonth(), GetYear()) && GetDay() > 0;
  }

  int DaysPassedToMonth(int month, int year) const {
    int days = 0;
    for (int i = 1; i < month; ++i) days += GetDaysInMonth(i, year);
  }

  int GetDays() const {
    int days = 0;
    for (int i = DEFAULT_DATE_YEAR; i < GetYear(); ++i)
      days += GetDaysInYear(i);
    return days + DaysPassedToMonth(GetMonth(), GetYear()) + GetDay();
  }

  void SetFromDays(int inp_days) {
    m = DEFAULT_DATE_MONTH;
    y = DEFAULT_DATE_YEAR;
    while (inp_days > GetDaysInYear(GetYear())) {
      inp_days -= GetDaysInYear(GetYear());
      ++y;
    }

    while (inp_days > DaysPassedToMonth(GetMonth() + 1, GetYear())) ++m;

    d = inp_days - DaysPassedToMonth(GetMonth(), GetYear());
  }

 public:
  Date(int day, int month, int year) : d{day}, m{month}, y{year} {
    if (!IsCorrectDate()) {
      d = DEFAULT_DATE_DAY;
      m = DEFAULT_DATE_MONTH;
      y = DEFAULT_DATE_YEAR;
    }
  }

  int GetDay() const { return d; }
  int GetMonth() const { return m; }
  int GetYear() const { return y; }

  Date &operator+(int d) {
    d += d;
    if (d > 31) {
      while (d > 31) {
        day -= 31;
        ++m;
      }
      while (m > 12) {
        m -= 12;
        ++y;
      }
    }
    // if (year == 2010) day = 1, month = 1, year = 1970;
    return *this;
  }
  Date &operator-(int d) {
    d -= d;
    if (day < 0) {
      while (d < 0) {
        d += 31;
        --m;
      }
      while (month < 1) {
        m += 12;
        --y;
      }
    }
    if (y == 1969) d = 1, m = 1, y = 1970;
    return *this;
  }
  Date &operator-(Date &d2) {
    Date date(this->GetDay(), this->GetMonth(), this->GetYear());
    this->d = this->day - d2.day;
    this->month = this->month - d2.month;
    this->year = this->year - d2.year;
    if (day < 0) {
      while (day < 0) {
        day += 31;
        --month;
      }
      while (month < 1) {
        month += 12;
        --year;
      }
    }
    return *this;
  }
};

int main() {
  Date date1(4, 4, 1971);
  Date date2(1, 1, 2004);
  date1 = date1 + 365;
  date1 = date1 - 365;
  date1 = date2 - date1;
  std::cout << date1.GetDay() << " " << date1.GetMonth() << " "
            << date1.GetYear() << "\n";
}