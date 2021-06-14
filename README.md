# reason-react-project-demo


## Description
This POC contains the source code for a Todo application built with ReasonReact and BuckleScript. A user can add and remove items from this list. It also contains a Login and a Sign Up page.


## Preview
![screenshot from 2019-02-22 12-42-40](https://user-images.githubusercontent.com/37612566/53225884-6e50cd80-369f-11e9-990e-ce2b2805a1bc.png)
![screenshot from 2019-02-21 11-53-46](https://user-images.githubusercontent.com/37612566/53148044-75100f80-35cf-11e9-9988-7f443fe5a834.png)
![screenshot from 2019-02-21 11-53-49](https://user-images.githubusercontent.com/37612566/53148045-75100f80-35cf-11e9-8dd0-528526f6ddf1.png)


## Getting Started
* [install Reason](https://reasonml.github.io/reason-react/docs/en/installation.html)

* [Download and install ReasonReact](https://reasonml.github.io/reason-react/docs/en/installation.html)


### Clone this repository
```bash
$ git clone <project url>
```

### Change directory
```bash
$ cd reason-react-project-demo
```

### Install dependencies
```bash
$ npm install or yarn install
```

### Run the application
```bash
$ npm start or yarn start
```

* Visit your app at [http://localhost:3000](http://localhost:3000).

### Project folder structure
```
src
│   index.re
│   routes.re  
│   registerServiceWorker.js
|   app.css
|
└───components
│   │   App.re
│   │   Button.re
│   │   Input.re
│   |   InputField.re
|   |   InputForm.re
|   |   Item.re
|   |   TodoType.re
│   
└───containers
|   │   SignIn.re
|   │   SignUp.re
|   |   TodoTask.re
```

## Technologies used in the app.

* [ReasonReact](https://reasonml.github.io/reason-react/) - A productive frontend framework
* [ReasonML](https://reasonml.github.io/) - Reason lets you write simple, fast and quality type safe code.

* [BuckleScript](https://bucklescript.github.io/) - Write safer and simpler code in OCaml & Reason, compile to JavaScript.

### For issue bsb.exe: unknown option '-color'. #75
https://github.com/rrdelaney/reason-scripts/issues/75#issue-350594936
