# Animation

## Animation Controller

- 🏄🏼‍♂️ Play an animation **forward** or in **reverse**, or **stop** an animation

- Set the animation to a **specific value**.

- Define the **upperBound** and **lowerBound** values of an animation.

- Create a **fling** animation effect using a physics simulation.

- A Ticker is an object that knows how to register itself with the SchedulerBinding and **fires a callback every frame** 🖼
  hospital

### TickerProvider

-

## Animation

### Tween

- A linear interpolation between a beginning and ending value.

  ```dart
  late AnimationController _controller;
  late Animation<Offset> animationBlue;
  animationBlue = Tween<Offset>(begin: Offset.zero, end: Offset.zero)
          .animate(CurvedAnimation(parent: _controller, curve: Curves.linear));
  ```

### Interval

- An Interval can be used to delay an animation

  ```dart
  late AnimationController _controller;
  late Animation<Offset> animationRed;

  _controller = AnimationController(vsync: this, duration: const Duratio(seconds: 6));
  /// a six second animation that uses an Interval 📉📉📉📉
  /// with its begin set to 0.5 and its end set to 1.0
  /// will essentially become a three-second animation that starts three seconds later.
  animationRed = Tween<Offset>(begin: Offset.zero, end: Offset.zero)
  .animate(CurvedAnimation(parent: _controller, curve: const Interval(0.5, 1,curve: Curves.linear)));
  ```
