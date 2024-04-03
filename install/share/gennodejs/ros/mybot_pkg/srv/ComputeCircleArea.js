// Auto-generated. Do not edit!

// (in-package mybot_pkg.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class ComputeCircleAreaRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.radius = null;
    }
    else {
      if (initObj.hasOwnProperty('radius')) {
        this.radius = initObj.radius
      }
      else {
        this.radius = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ComputeCircleAreaRequest
    // Serialize message field [radius]
    bufferOffset = _serializer.float64(obj.radius, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ComputeCircleAreaRequest
    let len;
    let data = new ComputeCircleAreaRequest(null);
    // Deserialize message field [radius]
    data.radius = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a service object
    return 'mybot_pkg/ComputeCircleAreaRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '34d1b51a3aa2a07a0194bc3c5de27677';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 radius
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ComputeCircleAreaRequest(null);
    if (msg.radius !== undefined) {
      resolved.radius = msg.radius;
    }
    else {
      resolved.radius = 0.0
    }

    return resolved;
    }
};

class ComputeCircleAreaResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.area = null;
    }
    else {
      if (initObj.hasOwnProperty('area')) {
        this.area = initObj.area
      }
      else {
        this.area = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ComputeCircleAreaResponse
    // Serialize message field [area]
    bufferOffset = _serializer.float64(obj.area, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ComputeCircleAreaResponse
    let len;
    let data = new ComputeCircleAreaResponse(null);
    // Deserialize message field [area]
    data.area = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a service object
    return 'mybot_pkg/ComputeCircleAreaResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '502b7bd5115b3b4f57d03446f9208d12';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    float64 area
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ComputeCircleAreaResponse(null);
    if (msg.area !== undefined) {
      resolved.area = msg.area;
    }
    else {
      resolved.area = 0.0
    }

    return resolved;
    }
};

module.exports = {
  Request: ComputeCircleAreaRequest,
  Response: ComputeCircleAreaResponse,
  md5sum() { return 'c314357897f85c5c2498418b07dbcead'; },
  datatype() { return 'mybot_pkg/ComputeCircleArea'; }
};
