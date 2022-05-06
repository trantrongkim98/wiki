# Performance

## Note

- Try to use `const` as much as possible

- Try to use StatelessWidget as much as possible

- Try to split the large widget to small widget as much as possible

- Don't Create a __AnimationController__ in a large Widget then setState __AnimationController__ in this widget

    This is avoid using AnimationController with setState

    - Use `AnimatedBuilder` and pass `AnimationController` for it to don't setState in large Widget

    - Move Widget that needs animation to child statefulWidget and start animation in this small statefullWidget

    - Tránh đặt code layout Counter trong hàm builder nếu giá trị của counter không thay đổi phụ thuộc vào AnimatedBuilder thay vào đó chuyển CounterWidget đến child và pass child của hàm builder vào trong child của builer widget

        ```dart
            AnimatedBuilder(
        animation: _controller,
        child: CounterWidget(
          counter: counter,
        ),
        builder: (_, child) => Transform(
          alignment: Alignment.center,
          transform: Matrix4.identity()
            ..setEntry(3, 2, 0.001)
            ..rotateY(360 * _controller.value * (pi / 180.0)),
          child: child,
        ),
      )
        ```

- Avoid using Opacity with AnimatedBuilder or animation

    - Use `FadeTransition` or `AnimatedOpacity` instead

- Use StateManagement to manage your app state

    - Use buildWhen of Bloc to manage widget rebuilds

    - The concept of Getx is that it will automatically rebuild if your data changes

- Use Widgets over Functions

    - ***Với Function widget, Flutter chỉ thấy 1 widget duy nhất dẫn tới chỉ cần có 1 thay đổi của 1 Function widget thì tất cả widget layout bằng Function sẽ rebuilds cùng nhau dẫn tới performance kém xem demo bên dưới để hiểu rõ hơn***

    - Use small widget instead for function widget `(_buildWidget())`

    - In the case of functions, the generated widget tree looks like this:

        ```dart
        Container
            Container
        ```

    - While with classes, the widget tree is:

        ```dart
            ClassWidget
                Container
                    ClassWidget
                        Container
        ```

- Use `const` for __Constructor__ as much as possible

- Use [nil](https://pub.dev/packages/nil) instead const `EmptyBox` widget

    - _It’s just a basic Element Widget that does and costs almost nothing._


## ListView

### High Resolution Image for memory, maybe low performance

- __addRepaintBoundaries__: each child is wrapped by default with this widget, which paint the child only once to have higher performance

- __addAutomaticKeepAlives__: each child is wrapped by default with this widget, which keeps every child’s state alive

    - These two properties are by default enabled, so in our case.. we can simply disable them so that the children which are not visible will be disposed and garbage collected automatically.

