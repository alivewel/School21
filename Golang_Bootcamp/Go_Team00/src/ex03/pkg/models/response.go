package models


type Response struct {
	Session_id string `json:"session_id"`
	Frequency  float64 `json:"frequency"`
	Timestamp  string `json:"timestamp"`
}
