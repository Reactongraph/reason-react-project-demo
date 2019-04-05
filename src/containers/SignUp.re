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

  //Validate email and password
  let validateUser = (email, password) => {
    if (String.length(email)> 12 && String.length(password) > 5) {
      true
    } else {
      false
    }
  }

  //Signup function to store data locally if email and password is valid
  let handleSubmit = state => {
    // convert data into string from JS code for storing data in local
    let isValidated = validateUser(state.email, state.password)
    if(isValidated) {
      let stringifiedLoginData = [%bs.raw {| JSON.stringify(state) |}];
      Dom.Storage.(localStorage |> setItem(loginDataKey, stringifiedLoginData));
      ReasonReact.Router.push("dashboard");
    } else {
      [%bs.raw {| alert("Enter valid email and password") |}];
    }
      ReasonReact.Update({email: state.email, password: state.password});
  };

  // define navigation
  let handleNavigation = () => {
    ReasonReact.Router.push("signin");
  };

  // defines initial state
  {
    ...component,
    initialState: () => {email: "", password: ""},

    reducer: action =>
      switch (action) {
      // update state of input email field
      | InputEmailText(email) => (
          state => ReasonReact.Update({...state, email})
        )
      // update state of input email field
      | InputPasswordText(password) => (
          state => ReasonReact.Update({...state, password})
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