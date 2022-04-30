# Golang

## Struct

### Method

- **_Go does not have classes. However, you can define methods on types_**

- **_Golang don't support overload method_**

    - <i>You can only declare a method with a receiver whose type is defined in the same package as the method<i>

- **Without Pointer can not update properties**

- **With Pointer we can change properties**

```go
   type Vertex struct {
       X, Y float64
   }
```

1. A method is a function with a special receiver argument.

   ```go
   func (v Vertex) Abs() float64 {
       return math.Sqrt(v.X*v.X + v.Y*v.Y)
   }
   ```

2. Declare method as function

   ```go
   func Abs(v Vertex) float64 {
       return math.Sqrt(v.X*v.X + v.Y*v.Y)
   }
   ```

3. Declare method with non-struct types

   ```go
   type MyFloat float64

   func (f MyFloat) Abs() float64 {
       if f < 0 {
           return float64(-f)
       }
       return float64(f)
   }
   ```

4. Declare method with struct is pointer

```go
func (v *Vertex) Scale(f float64) {
	v.X = v.X * f
	v.Y = v.Y * f
}

//v := Vertex{3, 4}
//v.Scale(10)
//-> v.X = 30 and v.Y = 40
```

- **Note:** 
    - Use the Poitner to avoid copy a big struct

    - Empty Interface can hold values of any type

    - One of the most ubiquitous interfaces is Stringer defined by the fmt package.

    - The error type is a built-in interface similar to fmt.Stringer