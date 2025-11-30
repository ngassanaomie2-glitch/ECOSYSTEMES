#include "Time.hpp"

namespace Ecosystem {
namespace Core {

Time::Time() : mLast(clock::now()), mDelta(0.f) {}
void Time::Tick() {
    auto now = clock::now();
    std::chrono::duration<float> dt = now - mLast;
    mDelta = dt.count();
    mLast = now;
}
float Time::GetDelta() const noexcept { return mDelta; }

} // namespace Core
} // namespace Ecosystem
Time.cpp
#ifndef ECOSYSTEM_CORE_TIME_HPP
#define ECOSYSTEM_CORE_TIME_HPP

#include <chrono>

namespace Ecosystem {
namespace Core {

class Time {
public:
    Time();
    void Tick();
    float GetDelta() const noexcept;
private:
    using clock = std::chrono::high_resolution_clock;
    clock::time_point mLast;
    float mDelta;
};

} // namespace Core
} // namespace Ecosystem

#endif // ECOSYSTEM_CORE_TIME_HPP
