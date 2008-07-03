# New ports collection makefile for:	beryl-settings
# Date created:				Oct 29 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	beryl-settings
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.beryl-project.org/${PORTVERSION}/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	flz/beryl/

MAINTAINER=	rnoland@2hip.net
COMMENT=	Beryl Settings Manager

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/beryl.pc:${PORTSDIR}/x11-wm/beryl-core \
		${LOCALBASE}/libdata/pkgconfig/beryl-settings-bindings.pc:${PORTSDIR}/x11-wm/beryl-settings-bindings
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USE_GL=		gl
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	pygtk2
USE_GETTEXT=	yes
USE_XORG=	glproto
USE_PYTHON=	2.4+

DEPRECATED=	No longer supported - Use compiz
EXPIRATION_DATE=	2008-08-02

INSTALLS_ICONS=	yes

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.include <bsd.port.mk>
