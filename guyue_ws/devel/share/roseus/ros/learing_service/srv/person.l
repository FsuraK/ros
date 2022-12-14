;; Auto-generated. Do not edit!


(when (boundp 'learing_service::person)
  (if (not (find-package "LEARING_SERVICE"))
    (make-package "LEARING_SERVICE"))
  (shadow 'person (find-package "LEARING_SERVICE")))
(unless (find-package "LEARING_SERVICE::PERSON")
  (make-package "LEARING_SERVICE::PERSON"))
(unless (find-package "LEARING_SERVICE::PERSONREQUEST")
  (make-package "LEARING_SERVICE::PERSONREQUEST"))
(unless (find-package "LEARING_SERVICE::PERSONRESPONSE")
  (make-package "LEARING_SERVICE::PERSONRESPONSE"))

(in-package "ROS")





(intern "*UNKNOWN*" (find-package "LEARING_SERVICE::PERSONREQUEST"))
(shadow '*UNKNOWN* (find-package "LEARING_SERVICE::PERSONREQUEST"))
(defconstant learing_service::personRequest::*UNKNOWN* 0)
(intern "*MALE*" (find-package "LEARING_SERVICE::PERSONREQUEST"))
(shadow '*MALE* (find-package "LEARING_SERVICE::PERSONREQUEST"))
(defconstant learing_service::personRequest::*MALE* 1)
(intern "*FEMALE*" (find-package "LEARING_SERVICE::PERSONREQUEST"))
(shadow '*FEMALE* (find-package "LEARING_SERVICE::PERSONREQUEST"))
(defconstant learing_service::personRequest::*FEMALE* 2)
(defclass learing_service::personRequest
  :super ros::object
  :slots (_name _age _sex ))

(defmethod learing_service::personRequest
  (:init
   (&key
    ((:name __name) "")
    ((:age __age) 0)
    ((:sex __sex) 0)
    )
   (send-super :init)
   (setq _name (string __name))
   (setq _age (round __age))
   (setq _sex (round __sex))
   self)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:age
   (&optional __age)
   (if __age (setq _age __age)) _age)
  (:sex
   (&optional __sex)
   (if __sex (setq _sex __sex)) _sex)
  (:serialization-length
   ()
   (+
    ;; string _name
    4 (length _name)
    ;; uint8 _age
    1
    ;; uint8 _sex
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;; uint8 _age
       (write-byte _age s)
     ;; uint8 _sex
       (write-byte _sex s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint8 _age
     (setq _age (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _sex
     (setq _sex (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(defclass learing_service::personResponse
  :super ros::object
  :slots (_result ))

(defmethod learing_service::personResponse
  (:init
   (&key
    ((:result __result) "")
    )
   (send-super :init)
   (setq _result (string __result))
   self)
  (:result
   (&optional __result)
   (if __result (setq _result __result)) _result)
  (:serialization-length
   ()
   (+
    ;; string _result
    4 (length _result)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _result
       (write-long (length _result) s) (princ _result s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _result
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _result (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass learing_service::person
  :super ros::object
  :slots ())

(setf (get learing_service::person :md5sum-) "c198113e7dd9cc5c9fd5f271c8479b39")
(setf (get learing_service::person :datatype-) "learing_service/person")
(setf (get learing_service::person :request) learing_service::personRequest)
(setf (get learing_service::person :response) learing_service::personResponse)

(defmethod learing_service::personRequest
  (:response () (instance learing_service::personResponse :init)))

(setf (get learing_service::personRequest :md5sum-) "c198113e7dd9cc5c9fd5f271c8479b39")
(setf (get learing_service::personRequest :datatype-) "learing_service/personRequest")
(setf (get learing_service::personRequest :definition-)
      "string name
uint8 age
uint8 sex

uint8 unknown = 0
uint8 male = 1
uint8 female = 2
---
string result

")

(setf (get learing_service::personResponse :md5sum-) "c198113e7dd9cc5c9fd5f271c8479b39")
(setf (get learing_service::personResponse :datatype-) "learing_service/personResponse")
(setf (get learing_service::personResponse :definition-)
      "string name
uint8 age
uint8 sex

uint8 unknown = 0
uint8 male = 1
uint8 female = 2
---
string result

")



(provide :learing_service/person "c198113e7dd9cc5c9fd5f271c8479b39")


