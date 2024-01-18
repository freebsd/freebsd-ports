WLR_SUFFIX=	016
SOVERSION=	11

LIB_DEPENDS:=	${LIB_DEPENDS:S/wlroots.so/&.${SOVERSION}/:S/wlroots$/&${WLR_SUFFIX}/}

USES+=		localbase # -isystem
CONFIGURE_ENV+=	PKG_CONFIG_PATH="${LOCALBASE}/wlroots${WLR_SUFFIX}/libdata/pkgconfig"
MAKE_ENV+=	PKG_CONFIG_PATH="${LOCALBASE}/wlroots${WLR_SUFFIX}/libdata/pkgconfig"
