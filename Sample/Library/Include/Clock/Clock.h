#ifndef U22_FRAMEWORK_CLOCK_CLOCK_H
#define U22_FRAMEWORK_CLOCK_CLOCK_H


#include "../Common/Common.h"

#include <deque>


namespace u22::clock {
class Clock {
private:
    //! 時間
    float _delta_time;
    //! 時間
    float _previous_time;
    //! 理想的なFPS
    float _ideal_fps;
    //! 現在のFPS
    float _now_fps;
    //! 標本数
    const int _sample_count;
    //! デルタタイムの合計値
    float _delta_times_sum;
    //! 標本
    std::deque<float> _delta_times;
    /// <summary>
    /// FPS算出
    /// </summary>
    /// <param name=""></param>
    void CalculateFPS(void);
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Clock();
    /// <summary>
    /// デンストラクタ
    /// </summary>
    ~Clock();
    /// <summary>
    /// ゲッター
    /// </summary>
    /// <param name=""></param>
    /// <returns>時間</returns>
    float GetFrameSecond(void) const;
    /// <summary>
    /// ゲッター
    /// </summary>
    /// <param name=""></param>
    /// <returns>理想的なFPS</returns>
    float GetIdealFPS(void) const noexcept;
    /// <summary>
    /// ゲッター
    /// </summary>
    /// <param name=""></param>
    /// <returns>現在のFPS</returns>
    float GetFPS(void) const noexcept;
    /// <summary>
    /// 単位時間に到達したか判定する
    /// </summary>
    /// <param name=""></param>
    /// <returns>しているならtrueを返す</returns>
    bool IsFull(void);
    /// <summary>
    /// 単位時間になるまで待つ
    /// </summary>
    /// <param name=""></param>
    void Wait(void);
    /// <summary>
    /// 時間を進める
    /// </summary>
    /// <param name=""></param>
    void Tick(void);
    /// <summary>
    /// 更新
    /// </summary>
    /// <param name=""></param>
    void Update(void);
};
}
#endif // !U22_FRAMEWORK_CLOCK_H