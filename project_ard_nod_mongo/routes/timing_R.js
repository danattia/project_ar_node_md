const express = require('express');
const router = express.Router()
module.exports = router;

const timing=require("../models/timing_m");

router.get('/Add',async (req, res) => {
    let timingD=await timing.find();
    res.render("timemnag", {
        pageTitle:"",
        item: timingD.length===0?{}:timingD[0],
        
    });
});


router.post('/Add',async(req, res) => {
    const datadb=await timing.find();
    
    if(datadb.length===0){
        const modelData = new timing({
               start:req.body.start,
              timereylay:req.body.timereylay,
               timeflash:req.body.timeflash,
               delay:req.body.timeflash
               
          });
           modelData.save();
    }else{
        const idPr=datadb[0]._id;
        const modelData = {
            start:req.body.start,
           timereylay:req.body.timereylay,
            timeflash:req.body.timeflash,
            delay:req.body.timeflash
            
       }
      
        await timing.findByIdAndUpdate(idPr,modelData);
    }
   
    res.redirect("/T/Add",);
});


router.get('/DAN/:dandan',async (req, res) => {
    let timingD=await timing.find();
    let time=timingD[0][req.params.dandan];
  res.send(time.toString()); 
    });












