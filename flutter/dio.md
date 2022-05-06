# Dio

- A powerful Http client for Dart, which supports __Interceptors__, __Global configuration__, __FormData__, __Request Cancellation__, __File downloading__, __Timeout etc__.

- Easy to customization `Http method`

- Easy to handle _request_ and _response_ with `Interceptor`

- Easy to handle `Cookie` with plugin `Cookie_Manager`

- Easy to send  file or multiple files with `FormData`

- _Easy to Handling Errors_

- Can `Transformer` for methods __PUT__, __POST__, and __PATCH__. with `dio.transformer`

- Support Proxy[link](#add-proxy-to-dio-http)

- Support `Cancellation` 🐤🐤🐤🐤🐤

- Support `HTTP2`

- Support `Transformer`

- Support `HttpClientAdapter`

- Support `Https certificate verification`

## Example

```dart
import 'package:dio/dio.dart';
void getHttp() async {
  try {
    var response = await Dio().get('http://www.google.com');
    print(response);
  } catch (e) {
    print(e);
  }
}
```

## Details

### Add Proxy to Dio http

```dart
import 'package:dio/dio.dart';
import 'package:dio/adapter.dart';
...
(dio.httpClientAdapter as DefaultHttpClientAdapter).onHttpClientCreate = (client) {
  // config the http client
  client.findProxy = (uri) {
    //proxy all request to localhost:8888
    return 'PROXY localhost:8888';
  };
  // you can also create a new HttpClient to dio
  // return HttpClient();
};
```