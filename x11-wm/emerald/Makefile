PORTNAME=	emerald
PORTVERSION=	0.8.8
PORTREVISION=	7
CATEGORIES=	x11-wm
MASTER_SITES=	https://BSDforge.com/projects/source/x11-wm/emerald/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Emerald Window Decorator
WWW=		http://www.beryl-project.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		Unfetchable

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:x11-wm/compiz
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libwnck-1.so:x11-toolkits/libwnck
RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USES=		desktop-file-utils gl gmake gnome libtool pathfix \
		pkgconfig shared-mime-info tar:bzip2 xorg
USE_GL=		gl
USE_GNOME=	cairo gtk20 intltool pango
USE_XORG=	x11 xrender
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE=		NLS
OPTIONS_DEFAULT=	NLS

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime gettext-tools

# XXX - might want to change that
post-patch:
	@${REINPLACE_CMD} 's|icons/gnome|icons/hicolor|' ${WRKSRC}/misc/Makefile.in
	@${REINPLACE_CMD} -e 's|#define GDK_DISABLE_DEPRECATED||g' \
	    -e 's|#define GTK_DISABLE_DEPRECATED||g' ${WRKSRC}/include/emerald.h
	@${REINPLACE_CMD} '/^emerald_LDADD =/s/$$/ -lm/' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
