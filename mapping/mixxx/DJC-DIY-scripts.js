function DJCDIY() {}

DJCDIY.wheelTurn = function (channel, control, value, status, group) {
    var newValue=(value-64);
    engine.setValue(group, "jog", newValue)   
    engine.scratchTick(1,newValue);
}