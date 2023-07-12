const mongoose = require('mongoose');

const dataSchema = new mongoose.Schema({
  
   start: {
        required: true,
        type: Number
    },
  
    timereylay: {
        required: true,
        type: Number
    },
   timeflash:{
        required:true,
        type: Number
    },
    delay:{
        required:true,
        type:  Number
    }
    
})

module.exports = mongoose.model('timing', dataSchema)
