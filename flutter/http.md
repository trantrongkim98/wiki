# HTTP

- A composable, Future-based library for making HTTP requests.

## Example

```dart
    import 'package:http/http.dart' as http;

    var url = Uri.parse('https://example.com/whatsit/create');
    var response = await http.post(url, body: {'name': 'doodle', 'color': 'blue'});
    print('Response status: ${response.statusCode}');
```

## Send other method

- create a Request object with method and uri
- add params or body to request

- call request.send() method

- Use Response.fromStream to parse **StreamedResponse** response

- final use response

  ```dart
      void network() async {
      final bytes = <int>[];
      var request = http.Request("Custom Method", Uri(host: ""))
          ..headers.addAll({})
          ..body = ""
          ..bodyBytes = bytes
          ..bodyFields = {}
          /// custom request
          ;
      http.StreamedResponse streamedResponse = await request.send();
      final response = await http.Response.fromStream(streamedResponse);
  }
  ```

## Custom HttpClient

- Sử dụng để xử lý Request, xứ lý Response

- Logging Request | Response

- Tạo Interceptors,...

```dart
class UserAgentClient extends http.BaseClient {
  final String userAgent;
  final http.Client _inner;

  UserAgentClient(this.userAgent, this._inner);

  Future<http.StreamedResponse> send(http.BaseRequest request) {
    request.headers['user-agent'] = userAgent;
    return _inner.send(request);
  }
}
```

## MultipartFile

- Send File as String

- Send File as Bytes

- Send File from path

```dart
    final bytes = <int>[];
    var uri = Uri.parse('https://example.com/create');
    var request = http.MultipartRequest('POST', uri)
      ..fields['user'] = 'nweiz@google.com'
      ..files.add(http.MultipartFile.fromBytes("package", bytes,filename: "package.tar.gz"))
      ..files.add(http.MultipartFile.fromString("package", base64UrlEncode(bytes),filename: "package.tar.gz"))
      ..files.add(
          await http.MultipartFile.fromPath('package', 'build/package.tar.gz'));
    var response = await request.send();
    if (response.statusCode == 200) print('Uploaded!');

```

## Retry

- A class wrapper on http.Client

- By default, Retries any response with **statusCode = 503**

- It waits 500ms before the first retry, and increases the delay by 1.5x each time.

```dart
import 'package:http/http.dart' as http;
import 'package:http/retry.dart';

Future<void> main() async {
  final client = RetryClient(http.Client());
  try {
    print(await client.read(Uri.parse('http://example.org')));
  } finally {
    client.close();
  }
}
```
