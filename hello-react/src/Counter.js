import React , {component, Component} from 'react';

class Counter extends Component{
    state = {
        number:0
    }
    
    handleIncrease = () =>{

        const {number} = this.state;
        this.setState({
            number : number+1
        });

        // this.setState(
        //     (state)=>({
        //         number:state.number
        //     })
        // );
    }

    handleDecrease= () => {
        this.setState(
            ({number})=>({
                number:number-1
            })
        );
    }//음수조건은 안넣나

    render(){
        return (
            <div>
                <h1>카운터</h1>
                <div>값 : {this.state.number}</div>
                <button onClick={this.handleIncrease}>+</button>
                <button onClick={this.handleDecrease}>-</button>
            </div>
        )
    }
}

export default Counter;