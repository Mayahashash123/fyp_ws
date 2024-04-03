
(cl:in-package :asdf)

(defsystem "mybot_pkg-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "ComputeCircleArea" :depends-on ("_package_ComputeCircleArea"))
    (:file "_package_ComputeCircleArea" :depends-on ("_package"))
  ))