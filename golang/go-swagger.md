# Go Swagger

<img align="right" width="180px" src="https://raw.githubusercontent.com/swaggo/swag/master/assets/swaggo.png">

[![image info](https://github.githubassets.com/images/modules/site/icons/footer/github-mark.svg)](https://github.com/swaggo/swag)


## Installing

1. Add swag to project


```shell
go install github.com/swaggo/swag/cmd/swag@latest
```

2. Add Comment to on the top of main function

```go
//	@title			Swagger Example API
//	@version		1.5
//	@description	This is a sample server Petstore server.
//	@termsOfService	http://swagger.io/terms/

//	@contact.name	API Support
//	@contact.url	http://www.swagger.io/support
//	@contact.email	support@swagger.io

//	@license.name	Apache 2.0
//	@license.url	http://www.apache.org/licenses/LICENSE-2.0.html

//
//	@host		localhost:3000
//	@BasePath	/
```

3. Define API

```go

// MakeSignInEndpoint
// AttributeExample godoc
//
//	@Summary		attribute example
//	@Description	attribute
//	@Tags			example
//	@Param			body body  SignInRequest true "Description"
//	@Router			/auth [POST]
func MakeSignInEndpoint(s service.Service) endpoint.Endpoint {
	return func(ctx context.Context, request interface{}) (interface{}, error) {
		...
	}
}
```

4. Initial Docs files

```shell
swag init -g "cmd/server/main.go" --parseInternal=true -d .,endpoints,service
```

## Usage

### I. Arguments meaning

- `-g`: Link to file `main.go`

- `-d`: link to folder you want generate docs

  - `.`: root directory of project

  - `endpoints`: directory to endpoints folder and sub-folder of it

  - `service`: directory to server folder and sub-folder of it

- `--parseInternal=true`: generage docs for project

- `--parseDependency=true`: generage docs for project dependencies





