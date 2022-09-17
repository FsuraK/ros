;; Auto-generated. Do not edit!


(when (boundp 'learing_topic::person)
  (if (not (find-package "LEARING_TOPIC"))
    (make-package "LEARING_TOPIC"))
  (shadow 'person (find-package "LEARING_TOPIC")))
(unless (find-package "LEARING_TOPIC::PERSON")
  (make-package "LEARING_TOPIC::PERSON"))

(in-package "ROS")
;;//! \htmlinclude person.msg.html


(intern "*UNKNOW*" (find-package "LEARING_TOPIC::PERSON"))
(shadow '*UNKNOW* (find-package "LEARING_TOPIC::PERSON"))
(defconstant learing_topic::person::*UNKNOW* 0)
(intern "*MALE*" (find-package "LEARING_TOPIC::PERSON"))
(shadow '*MALE* (find-package "LEARING_TOPIC::PERSON"))
(defconstant learing_topic::person::*MALE* 1)
(intern "*FEMALE*" (find-package "LEARING_TOPIC::PERSON"))
(shadow '*FEMALE* (find-package "LEARING_TOPIC::PERSON"))
(defconstant learing_topic::person::*FEMALE* 2)
(defclass learing_topic::person
  :super ros::object
  :slots (_name _sex _age ))

(defmethod learing_topic::person
  (:init
   (&key
    ((:name __name) "")
    ((:sex __sex) 0)
    ((:age __age) 0)
    )
   (send-super :init)
   (setq _name (string __name))
   (setq _sex (round __sex))
   (setq _age (round __age))
   self)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:sex
   (&optional __sex)
   (if __sex (setq _sex __sex)) _sex)
  (:age
   (&optional __age)
   (if __age (setq _age __age)) _age)
  (:serialization-length
   ()
   (+
    ;; string _name
    4 (length _name)
    ;; uint8 _sex
    1
    ;; uint8 _age
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;; uint8 _sex
       (write-byte _sex s)
     ;; uint8 _age
       (write-byte _age s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint8 _sex
     (setq _sex (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _age
     (setq _age (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get learing_topic::person :md5sum-) "612b7faf5bf6954824ea814f6f846838")
(setf (get learing_topic::person :datatype-) "learing_topic/person")
(setf (get learing_topic::person :definition-)
      "string name
uint8  sex
uint8  age

uint8 unknow = 0
uint8 male = 1
uint8 female = 2

")



(provide :learing_topic/person "612b7faf5bf6954824ea814f6f846838")


