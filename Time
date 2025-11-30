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
