# New ports collection makefile for:	beryl-manager
# Date created:				Oct 29 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	beryl-manager
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.beryl-project.org/${PORTVERSION}/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	flz/beryl/

MAINTAINER=	rnoland@2hip.net
COMMENT=	Manager for Beryl Composite/Window Manager

GNU_CONFIGURE=		yes
USE_GETTEXT=		yes
USE_BZIP2=		yes
USE_GMAKE=		yes
USE_PERL5_BUILD=	yes
USE_GNOME=		glib20 gtk20
INSTALLS_ICONS=		yes

DEPRECATED=	No longer supported - Use compiz
EXPIRATION_DATE=	2008-08-02

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

MAN1=		beryl-manager.1

.include <bsd.port.mk>
