#ifndef _TYPESYNTH_H_
#define _TYPESYNTH_H
// expression de type : (le type synthétisé pour les expressions)
// ce type est presque similaire à symbol_type mais il sert surtout pour ERROR_TYPE
typedef enum synthesized_type_expression { T_INT, T_BOOLEAN, AND_T, OR_T, GT_T, LT_T, ERROR_TYPE} synthesized_type_expression;

#endif
