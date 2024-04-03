;; Auto-generated. Do not edit!


(when (boundp 'mybot_pkg::ComputeCircleArea)
  (if (not (find-package "MYBOT_PKG"))
    (make-package "MYBOT_PKG"))
  (shadow 'ComputeCircleArea (find-package "MYBOT_PKG")))
(unless (find-package "MYBOT_PKG::COMPUTECIRCLEAREA")
  (make-package "MYBOT_PKG::COMPUTECIRCLEAREA"))
(unless (find-package "MYBOT_PKG::COMPUTECIRCLEAREAREQUEST")
  (make-package "MYBOT_PKG::COMPUTECIRCLEAREAREQUEST"))
(unless (find-package "MYBOT_PKG::COMPUTECIRCLEAREARESPONSE")
  (make-package "MYBOT_PKG::COMPUTECIRCLEAREARESPONSE"))

(in-package "ROS")





(defclass mybot_pkg::ComputeCircleAreaRequest
  :super ros::object
  :slots (_radius ))

(defmethod mybot_pkg::ComputeCircleAreaRequest
  (:init
   (&key
    ((:radius __radius) 0.0)
    )
   (send-super :init)
   (setq _radius (float __radius))
   self)
  (:radius
   (&optional __radius)
   (if __radius (setq _radius __radius)) _radius)
  (:serialization-length
   ()
   (+
    ;; float64 _radius
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _radius
       (sys::poke _radius (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _radius
     (setq _radius (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(defclass mybot_pkg::ComputeCircleAreaResponse
  :super ros::object
  :slots (_area ))

(defmethod mybot_pkg::ComputeCircleAreaResponse
  (:init
   (&key
    ((:area __area) 0.0)
    )
   (send-super :init)
   (setq _area (float __area))
   self)
  (:area
   (&optional __area)
   (if __area (setq _area __area)) _area)
  (:serialization-length
   ()
   (+
    ;; float64 _area
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _area
       (sys::poke _area (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _area
     (setq _area (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(defclass mybot_pkg::ComputeCircleArea
  :super ros::object
  :slots ())

(setf (get mybot_pkg::ComputeCircleArea :md5sum-) "c314357897f85c5c2498418b07dbcead")
(setf (get mybot_pkg::ComputeCircleArea :datatype-) "mybot_pkg/ComputeCircleArea")
(setf (get mybot_pkg::ComputeCircleArea :request) mybot_pkg::ComputeCircleAreaRequest)
(setf (get mybot_pkg::ComputeCircleArea :response) mybot_pkg::ComputeCircleAreaResponse)

(defmethod mybot_pkg::ComputeCircleAreaRequest
  (:response () (instance mybot_pkg::ComputeCircleAreaResponse :init)))

(setf (get mybot_pkg::ComputeCircleAreaRequest :md5sum-) "c314357897f85c5c2498418b07dbcead")
(setf (get mybot_pkg::ComputeCircleAreaRequest :datatype-) "mybot_pkg/ComputeCircleAreaRequest")
(setf (get mybot_pkg::ComputeCircleAreaRequest :definition-)
      "float64 radius

---

float64 area
")

(setf (get mybot_pkg::ComputeCircleAreaResponse :md5sum-) "c314357897f85c5c2498418b07dbcead")
(setf (get mybot_pkg::ComputeCircleAreaResponse :datatype-) "mybot_pkg/ComputeCircleAreaResponse")
(setf (get mybot_pkg::ComputeCircleAreaResponse :definition-)
      "float64 radius

---

float64 area
")



(provide :mybot_pkg/ComputeCircleArea "c314357897f85c5c2498418b07dbcead")


