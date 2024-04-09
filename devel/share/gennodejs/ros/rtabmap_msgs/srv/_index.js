
"use strict";

let ResetPose = require('./ResetPose.js')
let LoadDatabase = require('./LoadDatabase.js')
let CleanupLocalGrids = require('./CleanupLocalGrids.js')
let GetNodeData = require('./GetNodeData.js')
let DetectMoreLoopClosures = require('./DetectMoreLoopClosures.js')
let SetLabel = require('./SetLabel.js')
let ListLabels = require('./ListLabels.js')
let GlobalBundleAdjustment = require('./GlobalBundleAdjustment.js')
let GetNodesInRadius = require('./GetNodesInRadius.js')
let PublishMap = require('./PublishMap.js')
let AddLink = require('./AddLink.js')
let RemoveLabel = require('./RemoveLabel.js')
let GetPlan = require('./GetPlan.js')
let SetGoal = require('./SetGoal.js')
let GetMap2 = require('./GetMap2.js')
let GetMap = require('./GetMap.js')

module.exports = {
  ResetPose: ResetPose,
  LoadDatabase: LoadDatabase,
  CleanupLocalGrids: CleanupLocalGrids,
  GetNodeData: GetNodeData,
  DetectMoreLoopClosures: DetectMoreLoopClosures,
  SetLabel: SetLabel,
  ListLabels: ListLabels,
  GlobalBundleAdjustment: GlobalBundleAdjustment,
  GetNodesInRadius: GetNodesInRadius,
  PublishMap: PublishMap,
  AddLink: AddLink,
  RemoveLabel: RemoveLabel,
  GetPlan: GetPlan,
  SetGoal: SetGoal,
  GetMap2: GetMap2,
  GetMap: GetMap,
};
