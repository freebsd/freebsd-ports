# New ports collection makefile for:	kdebase2
# Date created:				Fri Apr 14 2000 15:05:00 EDT
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	kdebase
PORTVERSION=	2.2.2
PORTREVISION=	2
CATEGORIES?=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org

BUILD_DEPENDS=	autoconf213:${PORTSDIR}/devel/autoconf213 \
		automake14:${PORTSDIR}/devel/automake14
LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

USE_KDELIBS_VER=2
SOMAJOR=	4
SOMINOR=	0
USE_XPM=	yes
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	RUN_KAPPFINDER=no
CONFIGURE_ARGS+=--with-xdmdir=${X11BASE}/lib/X11/xdm \
		--with-qt-dir=${X11BASE} \
		--without-ldap --disable-closure
USE_GMAKE=	yes

.include "${.CURDIR}/../../x11/kde2/Makefile.kde"

.include <bsd.port.pre.mk>

.if exists(${X11BASE}/include/Xm/Xm.h)
WITH_MOTIF=	yes
.endif

.if defined(WITH_MOTIF) && ${WITH_MOTIF} == yes
USE_MOTIF=	yes
PLIST_SUB+=	MOTIF=""
.else
PLIST_SUB+=	MOTIF="@comment "
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with Motif support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_MOTIF=yes\""
	@${ECHO_MSG}
	@${ECHO_MSG} "Motif is used for Netscape plugin compatibility."
	@${ECHO_MSG}
.endif

post-extract:
	@${ECHO} "#!/bin/sh" > ${WRKSRC}/mkpamserv
	@${ECHO} "exit 0" >> ${WRKSRC}/mkpamserv

post-patch:
.if !defined(WITH_MOTIF)
	@${PERL} -pi -e 's/nsplugin//' \
		${WRKSRC}/konqueror/konqueror_config.desktop
.endif

pre-configure:
	${MKDIR} ${WRKSRC}/auto-bin
.for AC in autoconf autoheader
	${LN} -sf ${LOCALBASE}/bin/${AC}213 ${WRKSRC}/auto-bin/${AC}
.endfor
.for AM in automake aclocal
	${LN} -sf ${LOCALBASE}/bin/${AM}14 ${WRKSRC}/auto-bin/${AM}
.endfor
	cd ${WRKSRC} && env PATH=${WRKSRC}/auto-bin:$$PATH \
		${GMAKE} -f Makefile.cvs
	${PERL} -pi -e "s@version-info 3:0@version-info ${SOMAJOR}:${SOMINOR}@g" ${WRKSRC}/libkonq/Makefile.in
	${PERL} -pi -e "s@version-info 1:0:0@version-info ${SOMAJOR}:${SOMINOR}@g" ${WRKSRC}/khelpcenter/Makefile.in
	${PERL} -pi -e "s@version-info 1:1:0@version-info ${SOMAJOR}:${SOMINOR}@g" ${WRKSRC}/nsplugins/Makefile.in
	${PERL} -pi -e "s@TIME_WITH_SYS_TIME@INVALID_FOO@g" ${WRKSRC}/kioslave/ldap/kldap.h

post-configure:
	${PERL} -pi -e "s@444@644@g" ${WRKSRC}/kdesktop/init/Templates/Makefile

post-install:
	${CHMOD} u+s ${PREFIX}/bin/kcheckpass
.for file in kdmrc
.if !exists(${PREFIX}/share/config/kdm/${file})
	@${CP} ${PREFIX}/share/config/kdm/${file}.dist \
		${PREFIX}/share/config/kdm/${file}
.endif
.endfor

.include <bsd.port.post.mk>
