// defines states
type state = {
  email: string,
  password: string,
};

// defines actions
type action =
  | InputEmailText(string)
  | InputPasswordText(string)
  | Submit;

// defines Statefull component names Todo
let component = ReasonReact.reducerComponent("SignUp");
let loginDataKey = "loginDataKey";
let make = _children => {
  // Added new item in list
  let handleSubmit = state => {
    // convert data into string from JS code for storing data in local
    let stringifiedLoginData = [%bs.raw {| JSON.stringify(state) |}];
    Dom.Storage.(localStorage |> setItem(loginDataKey, stringifiedLoginData));

    let parseLoginData = [%bs.raw
      {| JSON.parse(localStorage.getItem("loginDataKey")) |}
    ];
    ReasonReact.Update({email: "", password: ""});
  };

  let handleNavigation = state => {
    ReasonReact.Router.push("signin");
  };

  // defines initial state
  {
    ...component,
    initialState: () => {email: "", password: ""},

    reducer: action =>
      switch (action) {
      // update state of input field
      | InputEmailText(newText) => (
          state => ReasonReact.Update({...state, email: newText})
        )
      | InputPasswordText(newText) => (
          state => ReasonReact.Update({...state, password: newText})
        )
      // Submit an items
      | Submit => (state => handleSubmit(state))
      },

    render: self => {
      let {email, password} = self.state;
      <div className="loginForm">
        <InputForm
          onSubmit={_ => self.send(Submit)}
          email
          password
          onEmailInputText={email => self.send(InputEmailText(email))}
          onPasswordInputText={password =>
            self.send(InputPasswordText(password))
          }
          buttonText="SignUp"
          onNavigation=handleNavigation
          navigationButtonText="Login"
          registrationTitle="Already have account?"
        />
      </div>;
    },
  };
};