# New ports collection makefile for:	kdebase2
# Date created:				Fri Apr 14 2000 15:05:00 EDT
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	kdebase
PORTVERSION=	2.1
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/distribution/tar/generic/src

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	kdeui.4:${PORTSDIR}/x11/kdelibs2 \
		intl.1:${PORTSDIR}/devel/gettext

USE_QT2=	yes
SOMAJOR=	4
SOMINOR=	0
MOC?=		${X11BASE}/bin/moc2
USE_XPM=	yes
USE_BZIP2=	yes
USE_NEWGCC=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=--with-xdmdir=${X11BASE}/lib/X11/xdm \
		--with-qt-dir=${X11BASE} \
		--with-qt-includes=${X11BASE}/include/qt2 \
		--with-qt-libraries=${X11BASE}/lib \
		--with-extra-libs=${LOCALBASE}/lib \
		--without-ldap \
		--disable-closure
CONFIGURE_ENV+=	MOC="${MOC}" LIBQT="-lqt2" \
		CPPFLAGS="-I${LOCALBASE}/include -I${PREFIX}/include -D_GETOPT_H ${PTHREAD_CFLAGS}" \
		LIBS="-Wl,-export-dynamic -L${LOCALBASE}/lib -ljpeg -lstdc++ -lgcc ${PTHREAD_LIBS}"
USE_GMAKE=	yes

pre-configure:
	${PERL} -pi -e "s@version-info 3:0@version-info ${SOMAJOR}:${SOMINOR}@g" ${WRKSRC}/libkonq/Makefile.in
	${PERL} -pi -e "s@version-info 1:0:0@version-info ${SOMAJOR}:${SOMINOR}@g" ${WRKSRC}/khelpcenter/Makefile.in
	${PERL} -pi -e "s@version-info 1:1:0@version-info ${SOMAJOR}:${SOMINOR}@g" ${WRKSRC}/nsplugins/Makefile.in
	${PERL} -pi -e "s@TIME_WITH_SYS_TIME@INVALID_FOO@g" ${WRKSRC}/kioslave/ldap/kldap.h

.include <bsd.port.mk>
