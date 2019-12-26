function light_on()
{
  var msgtext = "set 16 1";
  message = new Paho.MQTT.Message(msgtext);
  message.destinationName = "smart_greenhouse/1";
  client.send(message);
}

function light_off()
{
  var msgtext = "set 16 0";
  message = new Paho.MQTT.Message(msgtext);
  message.destinationName = "smart_greenhouse/1";
  client.send(message);
}

var client;
var message;
startConnection();

function startConnection() {
    client = new Paho.MQTT.Client("127.0.0.1", Number(1884), "rootuser");
    client.onConnectionLost = onConnectionLost;
    client.onMessageArrived = onMessageArrived;
    client.onMessageDelivered = onMessageDelivered;
    client.onConnectionLost = onConnectionLost;
    client.connect({onSuccess:onConnect});
}

function onConnect() {
  // Once a connection has been made, make a subscription.
  console.log("onConnect");
  client.subscribe("smart_greenhouse/1");
};
function onConnectionLost(responseObject) {
  if (responseObject.errorCode !== 0)
    console.log("onConnectionLost:"+responseObject.errorMessage);
};
function onMessageArrived(message) {
  console.log("onMessageArrived:"+message.payloadString);
};
function onMessageDelivered(message) {
  console.log("onMessageDelivered:"+message.payloadString);
};
function onConnectionLost() {
  console.log("Disconnect");
  client.connect();
};
