# $FreeBSD$

PORTNAME=	emerald
PORTVERSION=	0.8.8
PORTREVISION=	3
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Emerald Window Decorator

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:x11-wm/compiz
RUN_DEPENDS:=	${BUILD_DEPENDS}

INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
USE_GL=		gl
USES=		desktop-file-utils gettext gmake libtool pathfix \
		pkgconfig shared-mime-info tar:bzip2
USE_GNOME=	gtk20 intltool libwnck pango
USE_XORG=	xrender
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

# XXX - might want to change that
post-patch:
	@${REINPLACE_CMD} 's|icons/gnome|icons/hicolor|' ${WRKSRC}/misc/Makefile.in
	@${REINPLACE_CMD} -e 's|#define GDK_DISABLE_DEPRECATED||g' \
	    -e 's|#define GTK_DISABLE_DEPRECATED||g' ${WRKSRC}/include/emerald.h
	@${REINPLACE_CMD} '/^emerald_LDADD =/s/$$/ -lm/' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
