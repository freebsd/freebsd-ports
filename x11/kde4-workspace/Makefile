# New ports collection makefile for:	kdebase2
# Date created:				Fri Apr 14 2000 15:05:00 EDT
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	kdebase
PORTVERSION= 	1.90
CATEGORIES=	x11 kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR=	unstable/distribution/tar/src

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	kdeui.4:${PORTSDIR}/x11/kdelibs2 \
		Xpm.4:${PORTSDIR}/graphics/xpm \
		intl.1:${PORTSDIR}/devel/gettext

MOC?=		${X11BASE}/bin/moc2
USE_BZIP2=	yes
USE_QT2=	yes
INSTALLS_SHLIBS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+="--with-xdmdir=${X11BASE}/lib/X11/xdm" \
		--with-qt-dir=${X11BASE} \
		--with-qt-includes=${X11BASE}/include/qt2 \
		--with-qt-libraries=${X11BASE}/lib
CONFIGURE_ENV+=	MOC="${MOC}"
USE_GMAKE=	yes

FORBIDDEN=	"Local buffer overflow yielding gid nogroup"

.include <bsd.port.mk>
