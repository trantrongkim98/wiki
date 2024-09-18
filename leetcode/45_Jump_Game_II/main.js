/**
 * @param {number[]} nums
 * @return {number}
 */
var jump = function(nums) {
    let curIndex = 0,jumps= 0 ,maxJump = 0,endIndex = nums[0],lastIndex = nums.length-1;
    if(nums.length < 3) return nums.length-1;
    else if(nums[0]>= lastIndex) return 1;



    while(curIndex++ <= lastIndex){

        if(curIndex + nums[curIndex] >= maxJump){
            maxJump = curIndex + nums[curIndex];

        }

        if(curIndex == endIndex){
            jumps++;
            endIndex = maxJump;
            if(maxJump >= lastIndex){
                jumps++;
                break;
            }
            
        }

    }
    return jumps;
};

(()=>{

    const nums = [3,4,3,1,0,7,0,3,0,2,0,3]

    let jums = jump(nums);
    console.log(jums); // Output: 2
})()