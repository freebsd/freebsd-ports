# $FreeBSD$

PORTNAME=	emerald
PORTVERSION=	0.8.4
PORTREVISION=	8
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emerald Window Decorator

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:${PORTSDIR}/x11-wm/compiz
RUN_DEPENDS:=	${BUILD_DEPENDS}

INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
USE_GL=		gl
USES=		desktop-file-utils gettext gmake libtool pathfix pkgconfig \
		shared-mime-info tar:bzip2
USE_GNOME=	gtk20 libwnck pango
USE_XORG=	xrender
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

# XXX - might want to change that
post-patch:
	@${REINPLACE_CMD} 's|icons/gnome|icons/hicolor|' ${WRKSRC}/misc/Makefile.in
	@${REINPLACE_CMD} -e 's|#define GDK_DISABLE_DEPRECATED||g' \
	    -e 's|#define GTK_DISABLE_DEPRECATED||g' ${WRKSRC}/include/emerald.h

.include <bsd.port.mk>
