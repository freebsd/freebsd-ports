# New ports collection makefile for:	emerald
# Date created:				Oct 29 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	emerald
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.beryl-project.org/${PORTVERSION}/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	flz/beryl/

MAINTAINER=	rnoland@2hip.net
COMMENT=	Emerald Window Decorator

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/beryl.pc:${PORTSDIR}/x11-wm/beryl-core
RUN_DEPENDS+=	${BUILD_DEPENDS}

INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
USE_GL=		gl
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 libwnck pango gnomehack
USE_XORG=	xrender
USE_GETTEXT=	yes
USE_LDCONFIG=	yes

MAN1=		emerald.1 \
		emerald-theme-manager.1

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}"

# XXX - might want to change that
post-patch:
	@${REINPLACE_CMD} 's|icons/gnome|icons/hicolor|' ${WRKSRC}/misc/Makefile.in

.include <bsd.port.mk>
